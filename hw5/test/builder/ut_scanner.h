#include "../../src/builder/scanner.h"
#include<string>

TEST(scanner,nextCircle){
    std::string input = "I Circle eee ,tt{t3.14159a";
    Scanner s(input);
    std::string first=s.next();
    ASSERT_EQ("Circle",first);
    std::string second = s.next(); 
    ASSERT_EQ(",",second);
    double third = s.nextDouble(); 
    ASSERT_EQ(3.14159,third);
}

TEST(scanner,nextRectangle){
    std::string input = "Rectangle (3.14 4.00)";
    Scanner s(input);
    std::string first=s.next();
    ASSERT_EQ("Rectangle",first);
    std::string second = s.next(); 
    ASSERT_EQ("(",second);
    double third = s.nextDouble(); 
    ASSERT_EQ(3.14 ,third);
    double fourth = s.nextDouble();
    ASSERT_EQ(4.00 ,fourth);
    std::string fifth=")";
    ASSERT_EQ(")",fifth);
}

TEST(scanner,nextTriangle){
    std::string input = "Triangle ([3.00,12.43] [17.56,-4.00])";
    Scanner s(input);
    std::string first=s.next();
    ASSERT_EQ("Triangle",first);
    std::string second = s.next(); 
    ASSERT_EQ("(",second);
    std::string third = s.next(); 
    ASSERT_EQ("[",third);
    double fourth = s.nextDouble();
    ASSERT_EQ(3.00,fourth);
    std::string fifth=",";
    ASSERT_EQ(",",fifth);
}

TEST(scanner,nextCompoundShape){
    std::string input = "CompoundShape {\n  Circle (12.35)\n  CompoundShape {\n    Circle (1.10)\n    Rectangle (3.14 4.00)\n  }\n}\n";
    Scanner s(input);
    ASSERT_EQ("CompoundShape",s.next());
    ASSERT_EQ("{",s.next());
    ASSERT_EQ("Circle",s.next());
    ASSERT_EQ("(",s.next());
    ASSERT_EQ(12.35,s.nextDouble());
    ASSERT_EQ(")",s.next());
    ASSERT_EQ("CompoundShape",s.next());
    ASSERT_EQ("{",s.next());
    ASSERT_EQ("Circle",s.next());
    ASSERT_EQ("(",s.next());
    ASSERT_EQ(1.10,s.nextDouble());
    ASSERT_EQ(")",s.next());
    ASSERT_EQ("Rectangle",s.next());
    ASSERT_EQ("(",s.next());
    ASSERT_EQ(3.14,s.nextDouble());
    ASSERT_EQ(4.00,s.nextDouble());
    ASSERT_EQ(")",s.next());
    ASSERT_EQ("}",s.next());
    ASSERT_EQ("}",s.next());
}

TEST(scanner,nextException){
    std::string input = "I Circle eee ,tt{t3.14159a";
    Scanner s(input);
    std::string first=s.next();
    ASSERT_EQ("Circle",first);
    std::string second = s.next(); 
    ASSERT_EQ(",",second);
    double third = s.nextDouble(); 
    ASSERT_EQ(3.14159,third);
    try
    {
     std::string error = s.next();
     FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("end of scan!",e);
    }

    std::string input2 = "eeegfgfgh";
    Scanner s2(input2);
    try
    {
     std::string error2 = s2.next();
     FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("end of scan!",e);
    }

    std::string input3 = "     ";
    Scanner s3(input3);
    try
    {
     std::string error3 = s3.next();
     FAIL();
    }
    catch(std::string e)
    {
        ASSERT_EQ("end of scan!",e);
    }
}

TEST(scanner,nextDouble){
    std::string input = "asd 3.14.eee.  dfa5.66.12  6.7.6666";
    Scanner s(input);
    double first=s.nextDouble();
    ASSERT_EQ(3.14,first);
    double second=s.nextDouble();
    ASSERT_EQ(5.66,second);
    double third=s.nextDouble();
    ASSERT_EQ(12,third);
    ASSERT_EQ(6.7,s.nextDouble());
    ASSERT_EQ(6666,s.nextDouble());
}

TEST(scanner,nextDoubleException){
    std::string input = "asd 3.14  ";
    Scanner s(input);
    double first=s.nextDouble();
    ASSERT_EQ(3.14,first);
    try
    {
        s.nextDouble();
        FAIL();
    }
    catch( std::string  e)
    {
       ASSERT_EQ("end of scan!",e);
    }
    
    input="sssss";
     try
    {
        s.nextDouble();
        FAIL();
    }
    catch( std::string  e)
    {
       ASSERT_EQ("end of scan!",e);
    }
}

TEST(scanner,isdone){
    std::string input = "asd 3.14.eee.  dfa5.66.12  6.7.6666";
    Scanner s(input);
    double first=s.nextDouble();
    ASSERT_EQ(3.14,first);
    double second=s.nextDouble();
    ASSERT_EQ(5.66,second);
    double third=s.nextDouble();
    ASSERT_EQ(12,third);
    ASSERT_EQ(6.7,s.nextDouble());
    ASSERT_EQ(6666,s.nextDouble());
    ASSERT_EQ(true,s.isDone());
    try
    {
        s.nextDouble();
    }
    catch(std::string e)
    {
        ASSERT_EQ("end of scan!",e);
    }
}