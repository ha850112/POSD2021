#include <gtest/gtest.h>
#include "../src/list_item.h"

TEST(caselist_item,testlist_item){
    ListItem list("list1");
    ASSERT_EQ("- list1",list.getText());
}

TEST(caselist_item,testList_itemLevel)
{
     ListItem list("list1");
    ASSERT_EQ(0,list.getLevel()); 
}

TEST(caselist_item,testList_itemAdd)
{
    ListItem list("list1");
    try{
        list.add(new ListItem("text"));
    } catch(std::string e){
    ASSERT_EQ("You can't add anything to a ListItem or Text",e); 
    }

}