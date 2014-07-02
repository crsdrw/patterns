#include "stdafx.h"
#include "CppUnitTest.h"
#include "PatternsTest/MyStdOutCatcher.h"
#include "PatternsTest/MyAssert.h"
#include "PatternsLib/Strategy/MallardDuck.h"
#include "PatternsLib/Strategy/RedheadDuck.h"
#include "PatternsLib/Strategy/ModelDuck.h"
#include "PatternsLib/Strategy/DecoyDuck.h"
#include "PatternsLib/Strategy/RubberDuck.h"
#include "PatternsLib/Strategy/FlyRocketPowered.h"
#include "PatternsLib/SimUDuck/MallardDuck.h"
#include "PatternsLib/SimUDuck/RedheadDuck.h"
#include "PatternsLib/SimUDuck/RubberDuck.h"
#include "PatternsLib/SimUDuck/DecoyDuck.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PatternsTest
{
	TEST_CLASS(StrategyTest)
	{
	public:
		
		TEST_METHOD(TestMallardDuck)
		{
      MyStdOutCatcher stdOutCatcher;
      Patterns::MallardDuck mallard;
    
      mallard.display();
      MyAssert::AreEqual("I'm a real Mallard Duck\n", stdOutCatcher.read());

      mallard.performFly();
      MyAssert::AreEqual("I'm flying!!\n", stdOutCatcher.read());
      
      mallard.performQuack();
      MyAssert::AreEqual("Quack\n", stdOutCatcher.read());

      mallard.swim();
      MyAssert::AreEqual("All ducks float, even decoys!\n", stdOutCatcher.read());
    }

    TEST_METHOD(TestReadheadDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::RedheadDuck redhead;

      redhead.display();
      MyAssert::AreEqual("I'm a real Redhead Duck\n", stdOutCatcher.read());

      redhead.performFly();
      MyAssert::AreEqual("I'm flying!!\n", stdOutCatcher.read());

      redhead.performQuack();
      MyAssert::AreEqual("Quack\n", stdOutCatcher.read());
    }

    TEST_METHOD(TestModelDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::ModelDuck modelDuck;

      modelDuck.display();
      MyAssert::AreEqual("I'm a model Duck\n", stdOutCatcher.read());

      modelDuck.performFly();
      MyAssert::AreEqual("I can't fly\n", stdOutCatcher.read());

      modelDuck.performQuack();
      MyAssert::AreEqual("Quack\n", stdOutCatcher.read());
    }

    TEST_METHOD(TestRubberDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::RubberDuck rubberDuck;

      rubberDuck.display();
      MyAssert::AreEqual("I'm a rubber Duck\n", stdOutCatcher.read());

      rubberDuck.performFly();
      MyAssert::AreEqual("I can't fly\n", stdOutCatcher.read());

      rubberDuck.performQuack();
      MyAssert::AreEqual("Squeak\n", stdOutCatcher.read());
    }

    TEST_METHOD(TestDecoyDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::DecoyDuck decoyDuck;

      decoyDuck.display();
      MyAssert::AreEqual("I'm a decoy Duck\n", stdOutCatcher.read());

      decoyDuck.performFly();
      MyAssert::AreEqual("I can't fly\n", stdOutCatcher.read());

      decoyDuck.performQuack();
      MyAssert::AreEqual("<< Silence >>\n", stdOutCatcher.read());
    }

    TEST_METHOD(TestRocketPoweredModelDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::ModelDuck modelDuck;

      modelDuck.performFly();
      MyAssert::AreEqual("I can't fly\n", stdOutCatcher.read());

      modelDuck.setFlyBehaviour(Patterns::FlyRocketPowered::create());

      modelDuck.performFly();
      MyAssert::AreEqual("I'm flying with a rocket!\n", stdOutCatcher.read());
    }

    TEST_METHOD(SimUDuckTest)
    {
      MyStdOutCatcher stdOutCatcher;
      AntiPatterns::MallardDuck mallard;
      mallard.display();
      MyAssert::AreEqual("Looks like a mallard\n", stdOutCatcher.read());
      mallard.fly();
      MyAssert::AreEqual("Fly\n", stdOutCatcher.read());
      mallard.swim();
      MyAssert::AreEqual("All ducks float, even decoys!\n", stdOutCatcher.read());
      mallard.quack();
      MyAssert::AreEqual("Quack\n", stdOutCatcher.read());

      AntiPatterns::RedheadDuck redhead;
      redhead.display();
      MyAssert::AreEqual("Looks like a redhead\n", stdOutCatcher.read());

      AntiPatterns::RubberDuck rubberDuck;
      rubberDuck.display();
      MyAssert::AreEqual("Looks like a rubber duck\n", stdOutCatcher.read());
      rubberDuck.quack();
      MyAssert::AreEqual("Squeak\n", stdOutCatcher.read());
      rubberDuck.fly();
      MyAssert::AreEqual("I can't fly\n", stdOutCatcher.read());

      AntiPatterns::DecoyDuck decoyDuck;
      decoyDuck.display();
      MyAssert::AreEqual("Looks like a decoy duck\n", stdOutCatcher.read());
      decoyDuck.quack();
      MyAssert::AreEqual("<< Silence >>\n", stdOutCatcher.read());
      decoyDuck.fly();
      MyAssert::AreEqual("I can't fly\n", stdOutCatcher.read());
    }
	};
}