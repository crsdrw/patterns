using System;

namespace PatternsCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (Singleton.IsInstanceCreated)
                Console.WriteLine("You should be lazy!");
            var s1 = Singleton.Instance;
            var s2 = Singleton.Instance;
            if (s1 == s2)
                Console.WriteLine("There can be only one!");
            if (Singleton.IsInstanceCreated)
                Console.WriteLine("Instance created.");
            //var s3 = new Singleton(); // doesn't compile, good.
        }
    }
}
