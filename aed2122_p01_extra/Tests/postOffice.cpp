#include "postOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}


//--------

// b)
vector<Mail *> PostOffice::removePostman(string name) {
    vector<Mail *> res;
    vector<Postman>::const_iterator it;
	for(it = postmen.begin(); it < postmen.end(); it++){
	    if ((*it).getName() == name){
	        res = (*it).getMail();
	        postmen.erase(it);
	    }
	}
	return res;
}

// c)
vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {
    balance = 0;
	vector<Mail *> res;
	vector<Mail*>::const_iterator it;
	string zipCode;
	for(it = mailToSend.begin(); it < mailToSend.end(); it++){
	    balance += (*it)->getPrice();
	    zipCode = (*it)->getZipCode();
	    if(zipCode >= firstZipCode && zipCode < lastZipCode)
	        addMailToDeliver((*it));
	    else res.push_back((*it));
	}
	mailToSend.clear();
	return res;
}


Postman PostOffice::addMailToPostman(Mail *m, string name) {
    Postman p1;
    for (int i = 0; i < postmen.size(); i++) {
        if (postmen[i].getName() == name) {
            p1 = postmen[i];
            p1.addMail(m);
            return p1;
        }
    }
    throw NoPostmanException(name);
}

