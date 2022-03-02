#include <gtest/gtest.h>
#include "../src/paragraph.h"

TEST(caseParagraph,testParagraph){
  Paragraph p(1, "title");
  p.add(new ListItem("list1"));
  p.add(new ListItem("list2"));
  p.add(new Text("text"));
  Paragraph* p2 = new Paragraph(2, "title2");
  p2->add(new ListItem("list3"));
  p2->add(new ListItem("list4"));
  p2->add(new Text("sub text"));
  p.add(p2);
  
  ASSERT_EQ("# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text",p.getText());
}

TEST(caseParagraph,testParagraphlevel){
    try{
        Paragraph p(7, "title");

    }catch(std::string e){
        ASSERT_EQ ("A paragraph can only have a level between 1 and 6",e);
    }
}


TEST(caseParagraph,paragraphadd){
    Paragraph p(2,"text");
    Paragraph *p2 = new Paragraph(1,"text");
    try{
    p.add(p2);
    }catch(std::string e){
        ASSERT_EQ("New paragraphs have to be higher level than the previous ones",e);
    }

}