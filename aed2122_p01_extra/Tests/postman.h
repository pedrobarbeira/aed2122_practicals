#ifndef SRC_POSTMAN_H_
#define SRC_POSTMAN_H_

#include "mail.h"
#include <string>
#include <vector>

class Postman {
	unsigned int id;
	string name;
	vector<Mail *> myMail;

public:
	Postman();
	void setName(string nm);
	void addMail(Mail *m);
	void addMail(vector<Mail *> mails);
	string getName() const;
	vector<Mail *> getMail() const;
	unsigned int getID() const;
};

#endif /* SRC_POSTMAN_H_ */
