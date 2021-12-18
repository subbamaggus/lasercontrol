#include "gtest/gtest.h"
#include "Bluhmware.h"

class BluhmwareTest : public ::testing::Test
{
  
  protected:
  
  virtual void SetUp()
  {
    bw = new Bluhmware;
  }
  
  virtual void TearDown()
  {
    delete bw;
  }

  Bluhmware* bw;

};

//TEST_F(BluhmwareTest, test1) {    
//    EXPECT_EQ (bw->getLaser(),  -1);
//    bw.setLaser(12);
//    EXPECT_EQ (bw.getLaser(),  12);
//}

TEST(BluhmwareTest, test1) {    
//    EXPECT_EQ (bw->getLaser(),  -1);
//    bw.setLaser(12);
//    EXPECT_EQ (bw.getLaser(),  12);
}
