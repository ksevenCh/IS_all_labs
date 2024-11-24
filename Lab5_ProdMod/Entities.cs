using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5_ProdMod
{
    public enum FactType { Axioma = 0, Сonsequence, Target }
    public class Fact
    {
        public string name;
        public string description;
        public FactType FT;
        public List<Product> productsArg; //В которых он аргумент
        public List<Product> productsRes; //В которых он результат
        public bool isTrue = false;
        public bool isAxiomTrue = false;
        public Fact(string name, string description, FactType ft)
        {
            this.name = name;
            this.description = description;
            this.FT = ft;
            productsArg = new List<Product>();
            productsRes = new List<Product>();
        }

        public void FindProd(List<Product> products)
        {
            foreach (Product product in products)
            {
                if (product.inputFacts.Contains(this)) productsArg.Add(product);
                else if (product.result == this) productsRes.Add(product);
            }
        }

        public override string ToString()
        {
            return $"Fact Info: {name},{description},{FT.ToString()}";
        }

        public override bool Equals(object obj)
        {
            return name == (obj as Fact).name;
        }
    }

    public class Product
    {
        public string text;
        public List<Fact> inputFacts;
        public Fact result;
        public string description;

        public Product(string text)
        {
            this.text = text;
            inputFacts = new List<Fact>();
            result = new Fact("f00", "Нет факта", FactType.Сonsequence);
        }
    }

    public class Node
    {
       public Product prod;
       public List<Node> nextNodes = new List<Node>();

        public Node(Product p)
        {
            prod = p;
        }
    }
}
