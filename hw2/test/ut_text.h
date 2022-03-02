#include <gtest/gtest.h>
#include "../src/text.h"

TEST (casetext,testtext){
Text t("text");
ASSERT_EQ("text",t.getText());
ASSERT_EQ(0,t.getLevel());
}

TEST (caseText, TestTextLevel){
    Text txt("text");
    ASSERT_EQ(0,txt.getLevel());
}

TEST (caseText, TestTextadd){
   Text txt1("text");
   try{
        txt1.add(new Text("test"));
    }catch(std::string e){
            ASSERT_EQ("You can't add anything to a ListItem or Text", e);
    }
}