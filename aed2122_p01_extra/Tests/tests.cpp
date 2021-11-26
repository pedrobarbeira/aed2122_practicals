#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mail.h"
#include "postOffice.h"
#include "postman.h"
#include <string>

using testing::Eq;

TEST(test_1, getPrice){
    RegularMail m1("manuel", "ana","3330-454", 401);
    RegularMail m2("ana", "rui","4400-146", 10);
    GreenMail m3("maria", "luis","2520-110", "envelope");
    GreenMail m4("carla", "lara","7100-514", "box");

    EXPECT_EQ(140, m1.getPrice());
    EXPECT_EQ(50, m2.getPrice());
    EXPECT_EQ(80, m3.getPrice());
    EXPECT_EQ(240, m4.getPrice());
}


TEST(test_1, removePostman){
    PostOffice po;
    Postman p1;
    p1.setName("joao");
    p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
    Postman p2;
    p2.setName("paulo");
    p2.addMail(new RegularMail("rui", "ana","3330-454", 33));
    p2.addMail(new RegularMail("luis", "maria","8600-306", 67));
    p2.addMail(new RegularMail("carla", "lara","7100-514", 67));
    p2.addMail(new RegularMail("luis", "rui","4400-146", 33));
    Postman p3;
    p3.setName("fernando");
    p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
    po.addPostman(p1);
    po.addPostman(p2);
    po.addPostman(p3);

    vector <Mail *> mailP = po.removePostman("joao");
    EXPECT_EQ(1, mailP.size());
    EXPECT_EQ(2,po.getPostman().size());

    mailP.clear();
    mailP = po.removePostman("sergio");
    EXPECT_EQ(0, mailP.size());

    mailP.clear();
    mailP = po.removePostman("paulo");
    EXPECT_EQ(4, mailP.size());

    mailP.clear();
    mailP = po.removePostman("fernando");
    EXPECT_EQ(1, mailP.size());

    EXPECT_EQ(0,po.getPostman().size());
}

TEST(test_1, endOfDay){
    PostOffice po("2600-000", "3999-999");
    po.addMailToSend(new RegularMail("manuel", "ana","3330-454", 401));
    po.addMailToSend(new RegularMail("ana", "rui","4400-146", 10));
    po.addMailToSend(new GreenMail("maria", "luis","2520-110", "envelope"));
    po.addMailToSend(new GreenMail("carla", "lara","7100-514", "box"));

    unsigned int bal = 0;
    vector<Mail *> mailToOtherPO = po.endOfDay(bal);
    EXPECT_EQ(510, bal);
    EXPECT_EQ(3,mailToOtherPO.size());
    EXPECT_EQ(1,po.getMailToDeliver().size());
    EXPECT_EQ(0,po.getMailToSend().size());

    PostOffice po2("2600-000", "3999-999");
    po2.addMailToSend(new RegularMail("rita", "joana","3200-514", 120));

    mailToOtherPO = po2.endOfDay(bal);
    EXPECT_EQ(140, bal);
    EXPECT_EQ(0,mailToOtherPO.size());
    EXPECT_EQ(1,po2.getMailToDeliver().size());
    EXPECT_EQ(0,po2.getMailToSend().size());
}

TEST(test_1, addMailToPostman){
    PostOffice po;
    Postman p1;
    p1. setName("joao");
    p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
    p1.addMail(new RegularMail("luis", "rui","4400-146", 33));
    Postman p2;
    p2. setName("paulo");
    Postman p3;
    p3.setName("fernando");
    p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
    po.addPostman(p1);
    po.addPostman(p2);
    po.addPostman(p3);

    Postman px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"paulo");
    EXPECT_EQ(1,px.getMail().size());

    EXPECT_THROW(po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"luis"), NoPostmanException);

    try {
        px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"joao");
        EXPECT_EQ(3,px.getMail().size());
        px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"ricardo");
    }
        catch(NoPostmanException &e) {
        EXPECT_EQ("ricardo", e.getName());
    }

    px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"fernando");
    EXPECT_EQ(2,px.getMail().size());
}

