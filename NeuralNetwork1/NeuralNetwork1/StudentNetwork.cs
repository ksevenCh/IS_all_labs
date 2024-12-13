using System;
using System.Diagnostics;

namespace NeuralNetwork1
{
    public class StudentNetwork : BaseNetwork
    {
        public Stopwatch stopWatch = new Stopwatch();
        static Random random = new Random();
        public static double learningRate = 0.1;

        Neuron[] Sensors;
        Neuron[] Outputs;
        Neuron[][] Layers;

        public static double Sigmoid(double x)
        {
            return 1 / (1 + Math.Exp(-x));
        }

        private class Neuron
        {
            public Neuron[] inputs;
            public double output;
            public double[] weights;
            public double error;
            public double bias;

            private void InitRandWeights()
            {
                double standardDeviation = 1.0 / Math.Sqrt(weights.Length); 
                for (int i = 0; i < weights.Length; i++)
                {
                    weights[i] = random.NextDouble() * 2 * standardDeviation - standardDeviation;
                }
                bias = random.NextDouble() * 2 * standardDeviation - standardDeviation;
            }

            public void CorrectWeights()
            {
                for (int i = 0; i < weights.Length; i++)
                {
                    weights[i] = weights[i] - learningRate * error * inputs[i].output; // градиентный спуск
                }
                bias -= learningRate * error;
            }

            public Neuron(Neuron[] prevOnes = null)
            {
                if (prevOnes == null || prevOnes.Length == 0)
                    return;
                inputs = prevOnes;
                weights = new double[inputs.Length];
                InitRandWeights();
            }

            public void ActivateNeuron()
            {
                double sum = 0;
                sum += bias;
                for (int i = 0; i < inputs.Length; i++)
                {
                    sum += inputs[i].output * weights[i];
                }
                output = Sigmoid(sum);
            }
        }

        public StudentNetwork(int[] structure)
        {
            if (structure.Length < 2) throw new ArgumentException("Network must contain at least 2 Layers");

            Layers = new Neuron[structure.Length][];
            InitLayer(0, structure[0], null);

            for (int i = 1; i < structure.Length; i++)
                InitLayer(i, structure[i], Layers[i - 1]);

            Sensors = Layers[0];
            Outputs = Layers[Layers.Length - 1];
        }

        private void InitLayer(int layerIndex, int neuronCount, Neuron[] prevLayer)
        {
            Layers[layerIndex] = new Neuron[neuronCount];
            for (int j = 0; j < neuronCount; j++)
                Layers[layerIndex][j] = new Neuron(prevLayer);
        }

        private double[] RunOnSample(Sample img)
        {
            var res = Compute(img.input);
            img.ProcessPrediction(res);
            return res;
        }

        public override int Train(Sample sample, double acceptableError, bool parallel = false)
        {
            int iteration = 0;
            RunOnSample(sample);
            var err = sample.EstimatedError();
            while (err > acceptableError)
            {
                iteration++;
                RunOnSample(sample);
                err = sample.EstimatedError();
                BackPropagation(sample);
            }
            return iteration;
        }

        public override double TrainOnDataSet(SamplesSet samplesSet, int epochsCount, double acceptableError, bool parallel)
        {
            stopWatch.Restart();
            double err = 0;
            for (int epoch = 0; epoch < epochsCount; epoch++)
            {
                double errSum = 0;
                foreach (Sample sample in samplesSet.samples) 
                {
                    int trainRes = Train(sample, acceptableError);
                    if (trainRes == 0) errSum += sample.EstimatedError();
                }
                err = errSum;
                OnTrainProgress(((epoch + 1) * 1.0) / epochsCount, err, stopWatch.Elapsed);
            }
            stopWatch.Stop();
            return err;
        }

        protected override double[] Compute(double[] input)
        {
            for (int i = 0; i < Sensors.Length; i++)
                Sensors[i].output = input[i];

            for (int layer = 1; layer < Layers.Length; layer++)
                for (int j = 0; j < Layers[layer].Length; j++)
                    Layers[layer][j].ActivateNeuron();

            double[] result = new double[Outputs.Length];
            for (int i = 0; i < Outputs.Length; i++)
            {
                result[i] = Outputs[i].output;
            }
            return result;
        }

        private void BackPropagation(Sample sample)
        {
            for (int i = 0; i < Outputs.Length; i++)
            {
                Outputs[i].error = sample.error[i];
            }

            for (int layer = Layers.Length - 2; layer > 0; layer--)
            {
                for (int j = 0; j < Layers[layer].Length; j++)
                {
                    double sum = 0;
                    for (int l = 0; l < Layers[layer + 1].Length; l++)
                    {
                        sum += Layers[layer + 1][l].error * Layers[layer + 1][l].weights[j]; 
                    }
                    Layers[layer][j].error = sum * Layers[layer][j].output * (1 - Layers[layer][j].output); 
                }
            }

            for (int i = 0; i < Outputs.Length; ++i)
            {
                Outputs[i].CorrectWeights();
            }

            for (int layer = Layers.Length - 2; layer > 0; layer--)
            {
                for (int j = 0; j < Layers[layer].Length; ++j)
                {
                    Layers[layer][j].CorrectWeights();
                }
            }
        }
    }
}