using System;

namespace PatternsCSharp
{
    // See http://csharpindepth.com/articles/general/singleton.aspx
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
