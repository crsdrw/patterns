using System;

namespace PatternsCSharp
{
    public sealed class Singleton
    {
        private static readonly Lazy<Singleton> lazy =
            new Lazy<Singleton>(() => new Singleton());

        public static Singleton Instance { get { return lazy.Value; } }
        public static bool IsInstanceCreated { get { return lazy.IsValueCreated; } }  // optional

        private Singleton()
        {
        }
    }
}
