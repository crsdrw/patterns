#include "stdafx.h"
#include "CppUnitTest.h"
#include "PatternsTest/MyAssert.h"
#include "PatternsTest/MyLogger.h"
#include "PatternsTest/MyStdOutCatcher.h"
#include "PatternsLib/MallardDuck.h"
#include "PatternsLib/RedheadDuck.h"
#include "PatternsLib/ModelDuck.h"
#include "PatternsLib/DecoyDuck.h"
#include "PatternsLib/RubberDuck.h"
#include "PatternsLib/FlyRocketPowered.h"
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
      std::string expectedMallardDisplay("I'm a real Mallard Duck\n");
      Assert::AreEqual(expectedMallardDisplay, stdOutCatcher.read());

      mallard.performFly();
      std::string expectedMallardFly("I'm flying!!\n");
      Assert::AreEqual(expectedMallardFly, stdOutCatcher.read());
      
      mallard.performQuack();
      std::string expectedMallardQuack("Quack\n");
      Assert::AreEqual(expectedMallardQuack, stdOutCatcher.read());

      mallard.swim();
      std::string expectedMallardSwim("All ducks float, even decoys!\n");
      Assert::AreEqual(expectedMallardSwim, stdOutCatcher.read());
    }

    TEST_METHOD(TestReadheadDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::RedheadDuck redhead;

      redhead.display();
      std::string expectedReadheadDisplay("I'm a real Redhead Duck\n");
      Assert::AreEqual(expectedReadheadDisplay, stdOutCatcher.read());

      redhead.performFly();
      std::string expectedReadheadFly("I'm flying!!\n");
      Assert::AreEqual(expectedReadheadFly, stdOutCatcher.read());

      redhead.performQuack();
      std::string expectedReadheadQuack("Quack\n");
      Assert::AreEqual(expectedReadheadQuack, stdOutCatcher.read());
    }

    TEST_METHOD(TestModelDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::ModelDuck modelDuck;

      modelDuck.display();
      std::string expectedModelDisplay("I'm a model Duck\n");
      Assert::AreEqual(expectedModelDisplay, stdOutCatcher.read());

      modelDuck.performFly();
      std::string expectedModelFly("I can't fly\n");
      Assert::AreEqual(expectedModelFly, stdOutCatcher.read());

      modelDuck.performQuack();
      std::string expectedModelQuack("Quack\n");
      Assert::AreEqual(expectedModelQuack, stdOutCatcher.read());
    }

    TEST_METHOD(TestRubberDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::RubberDuck rubberDuck;

      rubberDuck.display();
      std::string expectedModelDisplay("I'm a rubber Duck\n");
      Assert::AreEqual(expectedModelDisplay, stdOutCatcher.read());

      rubberDuck.performFly();
      std::string expectedModelFly("I can't fly\n");
      Assert::AreEqual(expectedModelFly, stdOutCatcher.read());

      rubberDuck.performQuack();
      std::string expectedModelQuack("Squeak\n");
      Assert::AreEqual(expectedModelQuack, stdOutCatcher.read());
    }

    TEST_METHOD(TestDecoyDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::DecoyDuck decoyDuck;

      decoyDuck.display();
      std::string expectedModelDisplay("I'm a decoy Duck\n");
      Assert::AreEqual(expectedModelDisplay, stdOutCatcher.read());

      decoyDuck.performFly();
      std::string expectedModelFly("I can't fly\n");
      Assert::AreEqual(expectedModelFly, stdOutCatcher.read());

      decoyDuck.performQuack();
      std::string expectedModelQuack("<< Silence >>\n");
      Assert::AreEqual(expectedModelQuack, stdOutCatcher.read());
    }

    TEST_METHOD(TestRocketPoweredModelDuck)
    {
      MyStdOutCatcher stdOutCatcher;
      Patterns::ModelDuck modelDuck;

      modelDuck.performFly();
      std::string expectedModelFly("I can't fly\n");
      Assert::AreEqual(expectedModelFly, stdOutCatcher.read());

      modelDuck.setFlyBehaviour(Patterns::FlyRocketPowered::create());

      modelDuck.performFly();
      std::string expectedRocketPoweredModelFly("I'm flying with a rocket!\n");
      Assert::AreEqual(expectedRocketPoweredModelFly, stdOutCatcher.read());
    }

    TEST_METHOD(SimUDuckTest)
    {
      MyStdOutCatcher stdOutCatcher;
      AntiPatterns::MallardDuck mallard;
      mallard.display();
      Assert::AreEqual(std::string("Looks like a mallard\n"), stdOutCatcher.read());
      mallard.fly();
      Assert::AreEqual(std::string("Fly\n"), stdOutCatcher.read());
      mallard.swim();
      Assert::AreEqual(std::string("All ducks float, even decoys!\n"), stdOutCatcher.read());
      mallard.quack();
      Assert::AreEqual(std::string("Quack\n"), stdOutCatcher.read());

      AntiPatterns::RedheadDuck redhead;
      redhead.display();
      Assert::AreEqual(std::string("Looks like a redhead\n"), stdOutCatcher.read());

      AntiPatterns::RubberDuck rubberDuck;
      rubberDuck.display();
      Assert::AreEqual(std::string("Looks like a rubber duck\n"), stdOutCatcher.read());
      rubberDuck.quack();
      Assert::AreEqual(std::string("Squeak\n"), stdOutCatcher.read());
      rubberDuck.fly();
      Assert::AreEqual(std::string("I can't fly\n"), stdOutCatcher.read());

      AntiPatterns::DecoyDuck decoyDuck;
      decoyDuck.display();
      Assert::AreEqual(std::string("Looks like a decoy duck\n"), stdOutCatcher.read());
      decoyDuck.quack();
      Assert::AreEqual(std::string("<< Silence >>\n"), stdOutCatcher.read());
      decoyDuck.fly();
      Assert::AreEqual(std::string("I can't fly\n"), stdOutCatcher.read());
    }
	};
}