#include "stdafx.h"
#include "CppUnitTest.h"
#include "PatternsLib/ObjectPool/ObjectPool.h"

namespace {

  struct TestResource {
    bool in_use_{ false };
    void free() { in_use_ = false; }
  };

}  // namespace

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PatternsTest {

	TEST_CLASS(ObjectPoolTest) {
    typedef Patterns::ObjectPool<TestResource> TestPool;
	public:
		
		TEST_METHOD(TestCanGetObjectFromPool) {
      TestPool pool(5);
      auto resource = pool.getResource();
      Assert::IsTrue(resource != nullptr);
		}

    TEST_METHOD(TestCanReturnObjectToPool) {
      TestPool pool(5);
      TestResource* resource_ptr;
      {
         auto resource = pool.getResource();
         resource->in_use_ = true;
         resource_ptr = resource.get();
      }
      Assert::IsFalse(resource_ptr->in_use_);
    }

    TEST_METHOD(TestCanGetSharedPtrFromPool) {
      TestPool pool(5);
      TestResource* resource_ptr;
      {
        auto resource = pool.getResource();
        std::shared_ptr<TestResource> shared_resource(std::move(resource));
        Assert::IsTrue(resource == nullptr);  // check object has been stolen from unique_ptr
        shared_resource->in_use_ = true;
        resource_ptr = shared_resource.get();
      }
      Assert::IsTrue(resource_ptr != nullptr);
      Assert::IsFalse(resource_ptr->in_use_);
    }

	};
}