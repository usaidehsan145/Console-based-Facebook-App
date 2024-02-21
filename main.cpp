#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Base;
class User;
class Page;
class Activity;
class Post;
class Comment;
class Facebook;

class Helper
{
public:

	static int strlen(const char* str)     // performing the function same as strlen (getting length of a string)
	{
		int Count = 0;
		if (str)
		{
			while (str[Count] != '\0')
			{
				Count++;
			}
			Count;
		}

		return Count;
	}

	static void strcpy(char* dest, const char* src)     // copying string from one string to another
	{
		int size = strlen(src);

		for (int i = 0; i < size; i++)
		{
			dest[i] = src[i];
		}
	}

	static bool stringCompare(const char* str1, const char* str2)       // compare both strings and compare true if they are equal
	{
		int Size1 = Helper::strlen(str1);
		int Size2 = Helper::strlen(str2);
		if (Size1 == Size2)
		{
			for (int i = 0; i < Size1; i++)
			{
				if (str1[i] != str2[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	static char* GetStringFromBuffer(const char* temp)            // taking string from a temporary buffer and returning string
	{
		int size = strlen(temp);

		static char* str = nullptr;

		str = new char[size + 1];

		strcpy(str, temp);

		str[size] = '\0';

		return str;
	}
};

//--------------------------------------------BASE-----------------------------------------

class Base
{
protected:

	char* ID;

public:

	Base()
	{
		this->ID = nullptr;
	}
	Base(const char* id)
	{
		this->ID = Helper::GetStringFromBuffer(id);
	}
	~Base()
	{
		if (this->ID)
		{
			delete[] this->ID;
		}
	}
	void setID(char* id)
	{
		this->ID = Helper::GetStringFromBuffer(id);
	}
	char* getID()
	{
		return this->ID;
	}
	virtual void PrintName()
	{
		cout << "====  commented: ";
	}
	virtual void PrintOnlyName()
	{

	}
	virtual void ViewSharedInLastDay()
	{

	}
	Base* returnObj()
	{
		return this;
	}
};

//---------------------------------------------ACTIVITY-------------------------------------------

class Activity
{
	int type;
	char* value;

public:

	Activity()
	{
		this->type = 0;
		this->value = nullptr;
	}

	Activity(int Type, char* Value)
	{
		this->type = Type;
		this->value = Helper::GetStringFromBuffer(Value);
	}

	~Activity()
	{
		//cout << this->value << endl;
		if (this->value)
		{
			delete[] this->value;
		}
	}

	void setActivityType(int Type)
	{
		this->type = Type;
	}
	void setActivityValue(char* Value)
	{
		this->value = Helper::GetStringFromBuffer(Value);
	}
	int getActivityType()
	{
		return this->type;
	}
	char* getActivityValue()
	{
		return this->value;
	}

};

//------------------------------------------DATE---------------------------------------------

class Date
{

	int month;
	int day;
	int year;

public:

	static Date currentDate;
	Date()
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
	static void NowDate(int d, int m, int y)
	{
		currentDate.day = d;
		currentDate.month = m; currentDate.year = y;
	}
	Date(int d, int m, int y)
	{
		this->day = d;
		this->month = m;
		this->year = y;
	}
	static void setDay(int d)
	{
		currentDate.day = d;
	}
	static void setMonth(int m)
	{
		currentDate.month = m;
	}
	static void setYear(int y)
	{
		currentDate.year = y;
	}

	static int GetStaticDay()
	{
		return currentDate.day;
	}
	static int GetStaticMonth()
	{
		return currentDate.month;
	}
	static int GetStatictYear()
	{
		return currentDate.year;
	}

	void PrintDate()
	{
		cout << this->day << "/" << this->month << "/" << this->year;
	}

	static	void printStaticDate()
	{
		cout << "(" << currentDate.day << "/" << currentDate.month << "/" << currentDate.year << ")" << endl;
	}
	int GetDay()
	{
		return this->day;
	}
	int GetMonth()
	{
		return this->month;
	}
	int GetYear()
	{
		return this->year;
	}
	void SetDay(int d)
	{
		this->day = d;
	}
	void SetMonth(int d)
	{
		this->month = d;
	}
	void SetYear(int d)
	{
		this->year = d;
	}
};

Date Date::currentDate;

//---------------------------------------------COMMENT-------------------------------------------

class Comment : public Base
{
private:

	static int totalComments;
	char* commentText;
	Base* commentedBy;


public:

	Comment()
	{
		this->commentText = nullptr;
		this->commentedBy = nullptr;
	}

	Comment(const char* id) : Base(id)
	{
		this->commentText = nullptr;
		this->commentedBy = nullptr;
	}

	~Comment()
	{
		if (this->commentText)
		{
			delete[] this->commentText;
		}
	}

	void setText(const char* t)
	{
		this->commentText = Helper::GetStringFromBuffer(t);
	}

	char* getCommentText()
	{
		return this->commentText;
	}

	void setCommentedBy(Base* cmnt)
	{
		this->commentedBy = cmnt;
	}

	Base* getCommentedBy()
	{
		return this->commentedBy;
	}

	static void setTotalComments(int c)
	{
		totalComments = c;
	}

	static int getTotalComments()
	{
		return totalComments;
	}
};

int Comment::totalComments = 0;

//-------------------------------------------POST------------------------------------------------

class Post :public Base
{
	static int totalPosts;

	char* text;
	int postType;
	Date sharedDate;
	Activity* activity;
	Base* sharedBy;
	Base** likedBy;
	Comment** comment;

public:

	Post()
	{
		//this->ID = nullptr;
		this->text = nullptr;
		this->activity = nullptr;
		this->sharedBy = nullptr;
		this->sharedDate;
		this->postType = 0;

		this->likedBy = new Base * [10];
		for (int i = 0; i < 10; i++)
		{
			this->likedBy[i] = nullptr;
		}

		/*this->commentedBy = new Base * [10];
		for (int i = 0; i < 10; i++)
		{
			this->commentedBy[i] = nullptr;
		}*/

		this->comment = new Comment * [10];
		{
			for (int i = 0; i < 10; i++)
			{
				this->comment[i] = nullptr;
			}
		}
	}

	~Post()
	{
		if (this->text)
		{
			delete[] this->text;
		}

		if (this->activity)
		{
			delete this->activity;
		}

		if (this->sharedBy)
		{
			this->sharedBy = nullptr;
		}


		if (this->likedBy)
		{
			for (int i = 0; i < 10; i++)
			{
				this->likedBy[i] = nullptr;
			}
			delete[] this->likedBy;
		}

		if (this->comment)
		{
			for (int i = 0; i < 10; i++)
			{
				delete this->comment[i];
			}
			delete[] this->comment;
		}
	}

	virtual void PrintPostDetails()
	{
		if (this->postType == 2)
		{
			if (this->activity->getActivityType() == 1)
			{
				this->sharedBy->PrintOnlyName();
				cout << "feeling ";
			}

			else if (this->activity->getActivityType() == 2)
			{
				this->sharedBy->PrintOnlyName();
				cout << "thinking about  ";
			}

			else if (this->activity->getActivityType() == 3)
			{
				this->sharedBy->PrintOnlyName();
				cout << "making ";
			}

			else if (this->activity->getActivityType() == 4)
			{
				this->sharedBy->PrintOnlyName();
				cout << "celebrating ";
			}

			cout << this->activity->getActivityValue() << endl;

			cout << this->text << " ....(";
			this->sharedDate.PrintDate();
			cout << ")" << endl;
			for (int i = 0; i < 10; i++)
			{
				if (this->comment[i])
				{
					comment[i]->getCommentedBy()->PrintName();
					cout<<" Commented:	" << comment[i]->getCommentText();
					cout << endl;
				}
			}
		}

		else 
		{  
			this->sharedBy->PrintOnlyName();
			cout << "sharing '"<<this->text << "' ....(";
			this->sharedDate.PrintDate();
			cout << ")" << endl;
			for (int i = 0; i < 10; i++)
			{
				if (this->comment[i])
				{
					comment[i]->getCommentedBy()->PrintName();
					cout << comment[i]->getCommentText();
					cout << endl;
				}
			}
		}
		cout << endl << endl;
	}

	void printMemory()
	{
		cout << "(" << Date::GetStatictYear() - this->getSharedDate().GetYear() << " Years ago)" << endl;

		if (this->postType == 2)
		{
			if (this->activity->getActivityType() == 1)
			{
				this->sharedBy->PrintOnlyName();
				cout << "feeling ";
			}

			else if (this->activity->getActivityType() == 2)
			{
				this->sharedBy->PrintOnlyName();
				cout << "thinking about  ";
			}

			else if (this->activity->getActivityType() == 3)
			{
				this->sharedBy->PrintOnlyName();
				cout << "making ";
			}

			else if (this->activity->getActivityType() == 4)
			{
				this->sharedBy->PrintOnlyName();
				cout << "celebrating ";
			}

			cout << this->activity->getActivityValue() << endl;

			cout << this->text << " ....(";
			this->sharedDate.PrintDate();
			cout << ")" << endl;
		}

		else
		{
			this->sharedBy->PrintOnlyName();
			cout << "sharing '" << this->text << "' ....(";
			this->sharedDate.PrintDate();
			cout << ")" << endl;
		}
		cout  << endl;
	}

	void setPostID(char* id)
	{
		this->setID(id);
	}
	Base** GetLikedBy()
	{
		return this->likedBy;
	}
	char* getPostID()
	{
		return this->ID;
	}

	void setpostType(int p)
	{
		this->postType = p;
	}

	int getPostType()
	{
		return this->postType;
	}

	char* getPostText()
	{
		return this->text;
	}

	Date getSharedDate()
	{
		return this->sharedDate;
	}

	/*void printComments()
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->commentedBy[i])
			{
				Facebook obj;
				User* ptr = obj.SetCurrentUser(this->commentedBy[i]->getID());

				cout << ptr->getFirstName() << " " << ptr->getLastName() << " Wrote: " << this->comment[i]->getCommentText() << endl;
			}
		}
	}*/

	Base* getSharedBy()
	{
		return this->sharedBy;
	}

	Date& getDate()
	{
		return this->sharedDate;
	}

	Activity* getActivity()
	{
		return this->activity;
	}

	char* getText()
	{
		return this->text;
	}

	void setText(char* Text)
	{
		this->text = Helper::GetStringFromBuffer(Text);
	}

	void setActivity(Activity* act)
	{
		this->activity = act;
	}

	void setSharedBy(Base *base)
	{
		//this->sharedBy->setID(id);
		this->sharedBy = base;
	}

	bool setLikedBy(Base* base)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->likedBy[i] == nullptr)
			{
				this->likedBy[i] = base;
				return true;;
			}
			else
			{
				if (this->likedBy[i] == base)
				{
					cout << " Already Liked:-\n";
					return false;
				}
			}
		}
		return false;
	}

	bool setComment(Comment* cmnt)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->comment[i] == nullptr)
			{
				this->comment[i] = cmnt;
				return true;
			}

		}
		return false;
	}

	/*bool CommentedBy(Base* base)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->commentedBy[i] == nullptr)
			{
				this->commentedBy[i] = base;
				return true;
			}
		}
		return false;
	}*/

	static void setTotalPosts(int p)
	{
		totalPosts = p;
	}
	static int getTotalPosts()
	{
		return totalPosts;
	}
};

int Post::totalPosts = 0;

//---------------------------------------------PAGE------------------------------------------

class Page : public Base
{
private:

	static int totalPages;
	//char* PageId;
	char* PageName;
	Post** LikedBy;
	Post** TimeLine;

public:

	Page()
	{
		this->PageName = nullptr;

		this->LikedBy = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			this->LikedBy[i] = nullptr;
		}

		this->TimeLine = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			this->TimeLine[i] = nullptr;
		}
	}
	~Page()
	{

		if (this->PageName)
		{
			delete[] this->PageName;
		}
		if (LikedBy)
		{
			for (int i = 0; i < 10; i++)
			{
				this->LikedBy[i] = nullptr;
			}
			delete[] this->LikedBy;
		}
		if (this->TimeLine)
		{
			for (int i = 0; i < 10; i++)
			{
				this->TimeLine[i] = nullptr;
			}
			delete[] this->TimeLine;
		}

	}
	void ViewSharedInLastDay()
	{
		for (int i = 0; i < 10; i++)
		{
			Post* Ptr = this->TimeLine[i];

			if (Ptr)
			{
				if (Ptr->getDate().GetMonth() == Date::GetStaticMonth()) // Month Comparison
				{
					if (((Date::GetStaticDay() - Ptr->getDate().GetDay()) == 1) or ((Date::GetStaticDay() - Ptr->getDate().GetDay()) == 0))
					{
						Ptr->PrintPostDetails();
						cout << endl;
					}
				}
			}
		}
	}
	Post** GetTimeline()
	{
		return this->TimeLine;
	}
	Post** GetLikedBy()
	{
		return this->LikedBy;
	}
	void SetId(char* _Ptr)
	{
		this->ID = Helper::GetStringFromBuffer(_Ptr);
	}
	void SetName(char* _Name)
	{
		this->PageName = Helper::GetStringFromBuffer(_Name);
	}
	void printPages();
	Page* GetAddress()
	{
		return this;
	}
	char* getPageName();
	char* getPageId()
	{
		return this->ID;
	}
	void SetTimeLine(Post* p)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->TimeLine[i] == nullptr)
			{
				this->TimeLine[i] = p;
				break;
			}
		}
	}
	void PrintName()
	{
		cout << this->getID() << "	-" << this->getPageName() << ": ";
	}
	void PrintOnlyName()
	{
		cout << this->getPageName() << " is ";
	}

	void SetLikedBy(Post* like)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->LikedBy[i] == nullptr)
			{
				this->LikedBy[i] = like;
				break;
			}
		}
	}

	static int getTotalPages();
	static void setTotalPages(int t);
};

void Page::setTotalPages(int t)
{
	totalPages = t;
}

int Page::getTotalPages()
{
	return totalPages;
}

char* Page::getPageName()
{
	return this->PageName;
}

void Page::printPages()
{
	cout << this->ID << "	" << this->PageName << endl;
}

int Page::totalPages = 0;

//-----------------------------------------------USER-------------------------------------------------

class User : public Base
{
	//char* UserID;
	char* FirstName;
	char* LastName;
	User** FriendList;
	Page** LikedPages;
	Post** TimeLine;

	static int totalUsers;

public:

	User()
	{
		//this->ID = nullptr;
		FirstName = nullptr;
		LastName = nullptr;
		/*FriendList = nullptr;
		LikedPages = nullptr;*/

		int Max = 10;
		this->FriendList = new User * [Max];
		for (int i = 0; i < Max; i++)
		{
			this->FriendList[i] = nullptr;
		}
		this->LikedPages = new Page * [Max];
		for (int i = 0; i < Max; i++)
		{
			this->LikedPages[i] = nullptr;
		}
		this->TimeLine = new Post * [Max];
		for (int i = 0; i < Max; i++)
		{
			this->TimeLine[i] = nullptr;
		}
	}
	void SetFriend(User* Friend)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->FriendList[i] == nullptr)
			{
				this->FriendList[i] = Friend;
				break;
			}
		}
	}
	void SetLikedPage(Page* page)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->LikedPages[i] == nullptr)
			{
				this->LikedPages[i] = page;
				break;
			}
		}
	}
	void ViewSharedInLastDay()
	{
		for (int i = 0; i < 10; i++)
		{
			Post* Ptr = this->TimeLine[i];

			if (Ptr)
			{
				if (Ptr->getDate().GetMonth() == Date::GetStaticMonth()) // Month Comparison
				{
					if (((Date::GetStaticDay() - Ptr->getDate().GetDay()) == 1) or ((Date::GetStaticDay() - Ptr->getDate().GetDay()) == 0))
					{
						Ptr->PrintPostDetails();
						cout << endl;
					}
				}
			}
		}
	}
	void PrintName()
	{
		cout << this->getID() << "	-	" << this->FirstName << " " << this->LastName << ": ";
	}

	void PrintOnlyName()
	{
		cout << this->FirstName << " " << this->LastName << " is ";
	}
	void SetTimeLine(Post* p)
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->TimeLine[i] == nullptr)
			{
				this->TimeLine[i] = p;
				break;
			}
		}
	}
	void ViewUserTimeline()
	{
		this->PrintName(); cout << " - TimeLine " << endl << endl;
		for (int i = 0; i < 10; i++)
		{
			if (this->TimeLine[i])
			{
				this->TimeLine[i]->PrintPostDetails();
			}
		}
	}
	User** GetFriendList()
	{
		return this->FriendList;
	}
	void setId(char* id)
	{
		this->ID = id;
	}

	char* getID()
	{
		return this->ID;
	}
	void setFname(char* fn)
	{
		this->FirstName = fn;
	}
	void setLname(char* ln)
	{
		this->LastName = ln;
	}
	User* GetAddress()
	{
		return this;
	}
	char* getFirstName()
	{
		return this->FirstName;
	}

	char* getLastName()
	{
		return this->LastName;
	}
	static void setTotalUsers(int t);
	static int getTotalUsers();

	void ViewHomePageUsers()
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->FriendList[i])
			{
				this->FriendList[i]->ViewSharedInLastDay();
				//cout << endl;
			}
		}
	}

	void ViewHomePagePages()
	{
		for (int i = 0; i < 10; i++)
		{
			if (this->LikedPages[i])
			{
				this->LikedPages[i]->ViewSharedInLastDay();
				//cout << endl;
			}
		}
	}

	void printLikedPages()
	{
		for (int i = 0; i < 10; i++)
		{
			if (LikedPages[i])
			{
				cout << this->LikedPages[i]->getPageId() << "	- " << this->LikedPages[i]->getPageName() << endl;
			}
		}
	}

	void printFriendList()
	{
		for (int i = 0; i < 10; i++)
		{
			if (FriendList[i])
			{
				cout << this->FriendList[i]->ID << "	-	" << this->FriendList[i]->FirstName << " " << this->FriendList[i]->LastName << endl;
			}
		}
	}


	~User()
	{
		if (this->FirstName)
		{
			delete[] FirstName;
		}

		if (this->LastName)
		{
			delete[] LastName;
		}

		/*if (this->FriendList)
		{
			for (int i = 0; i < 10; i++)
			{
				delete []FriendList[i] = nullptr;
			}
			delete[] FriendList;
		}*/
		if (this->FriendList)
		{
			delete[] FriendList;
		}
		if (this->LikedPages)
		{
			/*for (int i = 0; i < 10; i++)
			{
				LikedPages[i] = nullptr;
			}*/
			delete[] LikedPages;
		}
		if (this->TimeLine)
		{
			for (int i = 0; i < 10; i++)
			{
				delete this->TimeLine[i] ;
			}
			delete[] this->TimeLine;
		}
	}
};

int User::totalUsers = 0;

void User::setTotalUsers(int t)
{
	totalUsers = t;
}

int User::getTotalUsers()
{
	return totalUsers;
}

//----------------------------------------------MEMORY--------------------------------------------

class Memory : public Post
{
	//char* PostText;
	Post* mem;

public:


	Memory()
	{
		//this->PostText = nullptr;
		this->mem = nullptr;
	}

	Memory(Post* ptr, const char* Text)
	{
		this->setText(Helper::GetStringFromBuffer(Text));
		this->mem = ptr;
	}

	void PrintPostDetails()
	{
		/*this->mem->getSharedBy()->PrintOnlyName();

		cout << "sharing a memory." << "(" << Date::GetStaticDay() << "/" << Date::GetStaticMonth() << "/" << Date::GetStatictYear() << ")" << endl;


		cout << endl;

		cout << "'" << PostText << "'" << endl << endl;

		if (this->mem->getPostType() == 2)
		{
			this->mem->getSharedBy()->PrintOnlyName();
			if(this->mem->getActivity()->getActivityType()==1)
			{
				cout << "feeling ";
			}

			else if (this->mem->getActivity()->getActivityType() == 2)
			{
				cout << "thinking about  ";
			}

			else if (this->mem->getActivity()->getActivityType() == 3)
			{
				cout << "making ";
			}

			else if (this->mem->getActivity()->getActivityType() == 4)
			{
				cout << "celebrating ";
			}

			cout << this->mem->getActivity()->getActivityValue() << endl;

			cout<<this->mem->getPostText() << " ....(";
			this->mem->getSharedDate().PrintDate();
			cout << ")" << endl;
		}

		else
		{
			this->mem->getSharedBy()->PrintOnlyName();
			cout << "sharing '" << this->mem->getPostText() << "' ....(";
			this->mem->getSharedDate().PrintDate();
			cout << ")" << endl;
		}
		cout << endl << endl;*/
		this->mem->getSharedBy()->PrintOnlyName();
		cout << "sharing a memory.";
		Date::printStaticDate();
		cout << endl;
		cout << "'" << this->getText() << "'" << endl;
		mem->printMemory();
	}

	~Memory()
	{
		/*if (this->PostText)
		{
			delete[] this->PostText;
		}*/
	}

	/*char* getpostText()
	{
		return this->PostText;
	}*/
};


//-------------------------------------------------FACEBOOK-----------------------------------------------

class Facebook
{
	User** UsersList;
	Page** PageList;
	Post** Posts;
	User* currentUser;

public:
	Facebook()
	{
		this->UsersList = nullptr;
		this->PageList = nullptr;
		this->Posts = nullptr;
		this->currentUser = nullptr;
	}


	void readUsers(const char* _UserFile)
	{
		if (this->PageList)
		{
			ifstream fin;
			fin.open(_UserFile);
			if (fin.is_open())
			{
				int Temp;
				fin >> Temp; // Number of Users

				User::setTotalUsers(Temp);

				this->UsersList = new User * [User::getTotalUsers()];
				for (int i = 0; i < User::getTotalUsers(); i++)
				{
					UsersList[i] = new User;
				}
				for (int i = 0; i < User::getTotalUsers(); i++)
				{
					//int Counter = 0;
					char buffer[80];

					fin >> buffer;// ID
					UsersList[i]->setId(Helper::GetStringFromBuffer(buffer));

					fin >> buffer; // FName
					UsersList[i]->setFname(Helper::GetStringFromBuffer(buffer));

					fin >> buffer; // LName
					UsersList[i]->setLname(Helper::GetStringFromBuffer(buffer));

					fin >> buffer;
					// Setting Friends
					while (buffer[0] != '-')
					{
						if (strlen(buffer) > 2)
						{
							int Number = ((buffer[1] - 48) * 10 + (buffer[2] - 48)) - 1;

							this->UsersList[i]->SetFriend(this->UsersList[Number]->GetAddress());
							fin >> buffer;
						}

						else
						{
							int Number = (buffer[1] - 48) - 1;
							this->UsersList[i]->SetFriend(this->UsersList[Number]->GetAddress());
							fin >> buffer;
						}

					}

					fin >> buffer;// liked Pages
					while (buffer[0] != '-')
					{
						if (strlen(buffer) > 2)
						{
							int Number = ((buffer[1] - 48) * 10 + (buffer[2] - 48)) - 1;


							this->UsersList[i]->SetLikedPage(this->PageList[Number]->GetAddress());
							fin >> buffer;
						}

						else
						{
							int Number = (buffer[1] - 48) - 1;
							this->UsersList[i]->SetLikedPage(this->PageList[Number]->GetAddress());
							fin >> buffer;
						}
					}
				}
				fin.close();
			}
		}
		else
		{
			cout << " File Not Found:-\n";
		}
	}


	void LoadData()
	{
		this->PageList = this->readPages("Pages.txt");
		readUsers("Users.txt");
		this->readPostsFromFile("Posts.txt");
		this->readCommentsFromFile("Comments.txt");
	}

	Page* SearchPageByID(const char* name)
	{
		bool flag;

		for (int i = 0; i < Page::getTotalPages(); i++)         // returns the student object if found against the roll number
		{
			flag = Helper::stringCompare(PageList[i]->getPageId(), name);
			if (flag == true)
			{
				return PageList[i];
			}
		}
		return nullptr;
	}

	void HomePage()
	{
		if (this->currentUser)
		{
			cout << "Home Page of " << this->currentUser->getFirstName() << " " << this->currentUser->getLastName() << endl << endl << endl;
			this->currentUser->ViewHomePageUsers();
			this->currentUser->ViewHomePagePages();
		}
	}

	void ViewTimeLine()
	{
		if (this->currentUser)
		{
			this->currentUser->ViewUserTimeline();
		}
	}

	bool SetCurrentUser(const char* name)
	{
		bool flag;

		for (int i = 0; i < User::getTotalUsers(); i++)         // returns the student object if found against the roll number
		{
			flag = Helper::stringCompare(UsersList[i]->getID(), name);
			if (flag == true)
			{
				this->currentUser = UsersList[i];
				cout << "User Set Successfully: " << endl;
				return true;
			}
		}

		return false;
	}

	Page** readPages(const char* FileName)
	{
		ifstream in;
		in.open(FileName);
		char Buffer[80];
		int Number;
		if (in.is_open())
		{
			in >> Number; // Total Number of Pages
			Page::setTotalPages(Number);
			Page** Temp = new Page * [Number];
			for (int i = 0; i < Number; i++)
			{
				Temp[i] = new Page();
				in >> Buffer; // PageID
				Temp[i]->SetId(Buffer); // Set PageID
				in.getline(Buffer, 80); // Set Name of Page
				Temp[i]->SetName(Buffer);
			}
			in.close();
			return Temp;
		}
		return nullptr;
	}
	void LikePost(const char* PostId)
	{
		Post* P = this->SearchPostbyID(PostId);
		if (P)
		{
			if (P->setLikedBy(this->currentUser))
			{
				//cout << " Post Liked :-\n";
			}
			else
			{
				//cout << " Post Liking Limit Reached:-\n";
			}
		}
		else
		{
			//cout << " No Post exist against Id " << PostId << endl;
		}
	}
	void CommentOnPost(const char* PostId, const char* commenttext)
	{
		Post* P = this->SearchPostbyID(PostId);
	 // P->CommentedBy(this->currentUser);
		int CommentNumber = Comment::getTotalComments();
		CommentNumber += 1;
		Comment::setTotalComments(CommentNumber);
		Comment* cmnt = new Comment("c" + CommentNumber);
		cmnt->setText(commenttext);
		cmnt->setCommentedBy(this->currentUser);
		P->setComment(cmnt);
	}
	void readPostsFromFile(const char* FileName)
	{
		ifstream in;
		in.open(FileName);
		char Buffer[80];
		int number;
		int date;
		int post_type;
		if (in.is_open())
		{
			in >> number;
			Post::setTotalPosts(number);

			this->Posts = new Post * [number];

			for (int i = 0; i < Post::getTotalPosts(); i++)
			{
				Posts[i] = new Post();

				in >> post_type;
				Posts[i]->setpostType(post_type);   // set post type i.e. simple or activity

				in >> Buffer;
				Posts[i]->setPostID(Buffer);      //set post id 

				in >> date;                      // set dates i.e. day, month, year
				Posts[i]->getDate().SetDay(date);

				in >> date;
				Posts[i]->getDate().SetMonth(date);

				in >> date;
				Posts[i]->getDate().SetYear(date);
				//char Buffer1[80];
				in.ignore();
				in.getline(Buffer, 80);
				Posts[i]->setText(Buffer);

				if (post_type == 2)
				{
					in >> date;                  // set post activity
					in.getline(Buffer, 80);

					this->Posts[i]->setActivity(new Activity(date, Buffer));   // set activity

					in >> Buffer;              // setsharedby

					if (strlen(Buffer) > 2)
					{
						int Number = ((Buffer[1] - 48) * 10 + (Buffer[2] - 48)) - 1;

						if (Buffer[0] == 'u')
						{
							//this->Posts[i]->setSharedBy(this->UsersList[Number]->getID());
							this->Posts[i]->setSharedBy(this->UsersList[Number]);
							this->UsersList[Number]->SetTimeLine(this->Posts[i]);
						}

						else
						{
							//this->Posts[i]->setSharedBy(this->PageList[Number]->getPageId());
							this->Posts[i]->setSharedBy(this->PageList[Number]);
							this->PageList[Number]->SetTimeLine(this->Posts[i]);
						}
					}

					else
					{
						int Number = (Buffer[1] - 48) - 1;

						if (Buffer[0] == 'u')
						{
							//this->Posts[i]->setSharedBy(this->UsersList[Number]->getID());
							this->Posts[i]->setSharedBy(this->UsersList[Number]);
							this->UsersList[Number]->SetTimeLine(this->Posts[i]);
						}

						else
						{
							//this->Posts[i]->setSharedBy(this->PageList[Number]->getPageId());
							this->Posts[i]->setSharedBy(this->PageList[Number]);
							this->PageList[Number]->SetTimeLine(this->Posts[i]);
						}
					}

				}

				else
				{
					in >> Buffer;

					if (strlen(Buffer) > 2)
					{
						int Number = ((Buffer[1] - 48) * 10 + (Buffer[2] - 48)) - 1;

						if (Buffer[0] == 'u')
						{
							//this->Posts[i]->setSharedBy(this->UsersList[Number]->getID());
							this->Posts[i]->setSharedBy(this->UsersList[Number]);
							this->UsersList[Number]->SetTimeLine(this->Posts[i]);
						}

						else
						{
							//this->Posts[i]->setSharedBy(this->PageList[Number]->getPageId());
							this->Posts[i]->setSharedBy(this->PageList[Number]);
							this->PageList[Number]->SetTimeLine(this->Posts[i]);
						}
					}

					else
					{
						int Number = (Buffer[1] - 48) - 1;

						if (Buffer[0] == 'u')
						{
							//this->Posts[i]->setSharedBy(this->UsersList[Number]->getID());
							this->Posts[i]->setSharedBy(this->UsersList[Number]);
							this->UsersList[Number]->SetTimeLine(this->Posts[i]);
						}

						else
						{
							//this->Posts[i]->setSharedBy(this->PageList[Number]->getPageId());
							this->Posts[i]->setSharedBy(this->PageList[Number]);
							this->PageList[Number]->SetTimeLine(this->Posts[i]);
						}
					}
				}

				in >> Buffer;               // liked by

				while (Buffer[0] != '-')
				{
					if (strlen(Buffer) > 2)
					{
						int Number = ((Buffer[1] - 48) * 10 + (Buffer[2] - 48)) - 1;

						if (Buffer[0] == 'u')
						{
							this->Posts[i]->setLikedBy(this->UsersList[Number]->returnObj());
						}

						else
						{
							this->Posts[i]->setLikedBy(this->PageList[Number]->returnObj());
						}
					}

					else
					{
						int Number = (Buffer[1] - 48) - 1;

						if (Buffer[0] == 'u')
						{
							this->Posts[i]->setLikedBy(this->UsersList[Number]->returnObj());
						}

						else
						{
							this->Posts[i]->setLikedBy(this->PageList[Number]->returnObj());
						}
					}

					in >> Buffer;
				}
			}
		}
	}
	void ViewPost(const char* PostId)
	{
		for (int i = 0; i < Post::getTotalPosts(); i++)
		{
			if (Helper::stringCompare(this->Posts[i]->getID(), PostId))
			{
				this->Posts[i]->PrintPostDetails();
				break;
			}
		}
	}
	void readCommentsFromFile(const char* FileName)
	{
		int postNumber = 0;
		ifstream in;
		in.open(FileName);
		char Buffer[80];
		int number;

		if (in.is_open())
		{
			in >> number;
			Comment::setTotalComments(number);

			for (int i = 0; i < Comment::getTotalComments(); i++)
			{
				Comment* comment = new Comment;

				in >> Buffer;            // set comment ID
				comment->setID(Buffer);

				in >> Buffer;            // setting post ID

				if (strlen(Buffer) > 5)
				{
					int Number = ((Buffer[4] - 48) * 10 + (Buffer[5] - 48)) - 1;
					postNumber = Number;
					this->Posts[Number]->setComment(comment);

				}

				else
				{
					int Number = (Buffer[4] - 48) - 1;
					postNumber = Number;
					this->Posts[Number]->setComment(comment);
				}

				in >> Buffer;

				if (Buffer[0] == 'u')             // if user commented 
				{
					if (strlen(Buffer) > 2)
					{
						int Number = ((Buffer[1] - 48) * 10 + (Buffer[2] - 48)) - 1;
						comment->setCommentedBy(this->UsersList[Number]);
						//this->Posts[postNumber]->CommentedBy(this->UsersList[Number]->returnObj());
					}

					else
					{
						int Number = (Buffer[1] - 48) - 1;
						comment->setCommentedBy(this->UsersList[Number]);
						//this->Posts[postNumber]->CommentedBy(this->UsersList[Number]->returnObj());
					}
				}

				else                               // if page commented
				{
					if (strlen(Buffer) > 2)
					{
						int Number = ((Buffer[1] - 48) * 10 + (Buffer[2] - 48)) - 1;
						comment->setCommentedBy(this->UsersList[Number]);
						//	this->Posts[postNumber]->CommentedBy(this->PageList[Number]->returnObj());
					}

					else
					{
						int Number = (Buffer[1] - 48) - 1;
						comment->setCommentedBy(this->UsersList[Number]);
						//this->Posts[postNumber]->CommentedBy(this->PageList[Number]->returnObj());
					}
				}

				in.getline(Buffer, 80);
				comment->setText(Buffer);
			}
		}

		else
		{
			cout << "file not found: " << endl;
		}
	}
	void PeopleLikedPost(const char* PostId)
	{
		Post* Ptr = this->SearchPostbyID(PostId);
		if (Ptr)
		{
			if (Ptr->GetLikedBy())
			{
				for (int i = 0; i < 10; i++)
				{
					if (Ptr->GetLikedBy()[i])
					{
						Ptr->GetLikedBy()[i]->PrintName();
					}
				}
			}
		}
	}
	void ViewLikedPost(const char* Id)
	{
		bool Flag = true;
		// Post liked by User
		for (int i = 0; i < Post::getTotalPosts() and Flag; i++)
		{
			if (Helper::stringCompare(Posts[i]->getID(), Id))
			{
				Base** Dptr = this->Posts[i]->GetLikedBy();
				for (int i = 0; Dptr[i]; i++)
				{
					User* Ptr = this->SearchUserbyID(Dptr[i]->getID());
					cout << " Post Liked by : " << Ptr->getFirstName() << " " << Ptr->getLastName() << endl;
				}
				Flag = false;
			}
		}

		Flag = true;
		// Post liked by Page
		for (int i = 0; i < Page::getTotalPages() and Flag; i++)
		{
			if (Helper::stringCompare(Posts[i]->getID(), Id))
			{
				Base** Dptr = Posts[i]->GetLikedBy();
				for (int i = 0; Dptr[i]; i++)
				{
					Page* Ptr = this->SetPagebyID(Dptr[i]->getID());
					if (Ptr)
					{
						cout << " Post Liked by : " << Ptr->getPageName() << endl;
					}
				}
			}
			Flag = false;
		}
	}
	void ViewPage(const char* PageId)
	{
		Page* Ptr = this->SearchPageByID(PageId);
		if (Ptr)
		{
			cout << Ptr->getPageName() << endl;
			for (int i = 0; Ptr->GetTimeline()[i]; i++)
			{
				Ptr->GetTimeline()[i]->PrintPostDetails();
			}
		}
		else
		{
			cout << " No Page of this ID:-\n";
		}
	}
	Post* SearchPostbyID(const char* postId)
	{
		bool flag;

		for (int i = 0; i < Post::getTotalPosts(); i++)         // returns the student object if found against the roll number
		{
			flag = Helper::stringCompare(Posts[i]->getID(), postId);
			if (flag == true)
			{
				return Posts[i];
			}
		}
		return nullptr;
	}
	Page* SetPagebyID(const char* PageID)
	{
		bool flag;

		for (int i = 0; i < Page::getTotalPages(); i++)         // returns the student object if found against the roll number
		{
			flag = Helper::stringCompare(PageList[i]->getID(), PageID);
			if (flag == true)
			{
				return PageList[i];
			}
		}
		return nullptr;
	}

	void getUserFname()
	{
		if (this->currentUser)
		{
			cout << this->currentUser->getFirstName() << " ";
		}
	}
	void getUserLname()
	{
		if (this->currentUser)
		{
			cout<<this->currentUser->getLastName();
		}
	}

	void PrintFriendList()
	{
		if (this->currentUser)
		{
			this->currentUser->printFriendList();
		}
	}

	void UserTimeLine()
	{
		if (this->currentUser)
		{
			this->currentUser->ViewUserTimeline();
		}
	}

	void PrintLikedPages()
	{
		if (this->currentUser)
		{
			this->currentUser->printLikedPages();
		}
	}

	void shareMemory(const char* postID,const char* text)
	{
		Post* ptr = this->SearchPostbyID(postID);

		if (Date::GetStatictYear() - ptr->getSharedDate().GetYear() >= 2)
		{
			if (Date::GetStaticMonth() == ptr->getSharedDate().GetMonth() and Date::GetStaticDay() == ptr->getSharedDate().GetDay())
			{
				Memory* memory = new Memory(ptr, text);
				this->currentUser->SetTimeLine(memory);
			}
		}

		else
		{
			cout << "no memory available: " << endl << endl;
		}

	}

	User* SearchUserbyID(const char* userID)
	{
		bool flag;

		for (int i = 0; i < User::getTotalUsers(); i++)         // returns the student object if found against the roll number
		{
			flag = Helper::stringCompare(UsersList[i]->getID(), userID);
			if (flag == true)
			{
				return UsersList[i];
			}
		}

		return nullptr;
	}
	~Facebook()
	{
		if (this->UsersList)
		{
			for (int i = 0; i < User::getTotalUsers(); i++)
			{
				delete this->UsersList[i];
			}
			delete[] this->UsersList;
		}

		if (this->PageList)
		{
			for (int i = 0; i < Page::getTotalPages(); i++)
			{
				delete this->PageList[i];
			}
			delete[] this->PageList;
		}

		if (this->Posts)
		{
			for (int i = 0; i < Post::getTotalPosts(); i++)
			{
				delete this->Posts[i];
			}
			delete[] this->Posts;
		}

		if (this->currentUser)
		{
			this->currentUser = nullptr;
		}
	}
};


int main()
{
	Date::NowDate(15, 11, 2017);
	Facebook fb;
	Date::currentDate.setDay(15);
	Date::currentDate.setMonth(11);
	Date::currentDate.setYear(2017);

	fb.LoadData();

	fb.SetCurrentUser("u7");
	if (fb.SetCurrentUser("u7"))
	{
		fb.getUserFname(); fb.getUserLname();cout << " Successfully set as Current User. " << endl;
		cout << "Command:	View Friend List" << endl;
		cout << "----------------------------------------------------------------------" << endl << endl;
		fb.getUserFname(); fb.getUserLname(); cout << " - Friend List" << endl;
		fb.PrintFriendList();
		cout << endl;

		cout << "Command:	View Liked Pages" << endl;
		cout << "----------------------------------------------------------------------" << endl << endl;
		fb.getUserFname(); fb.getUserLname(); cout << " - Liked Pages" << endl;
		fb.PrintLikedPages();
	}

	else
	{
		cout << "User not Found! " << endl;
	}

	cout << endl;

	cout << "Command:		Search Page: " << endl << endl;

	Page* page = fb.SearchPageByID("p7");
	if (page)
	{
		page->printPages();
	}
	else
	{
		cout << "page not found! " << endl;
	}

	cout << "Command		View Home " << endl << endl;
	cout << "----------------------------------------------------------------------" << endl << endl;

	fb.HomePage();

	cout << "Command		View TimeLine " << endl << endl;
	cout << "----------------------------------------------------------------------" << endl << endl;

	fb.ViewTimeLine();

	cout << "Command		View Liked Posts " << endl << endl;
	cout << "----------------------------------------------------------------------" << endl << endl;

	fb.PeopleLikedPost("post5");

	cout << endl << endl;

	cout << "Command		Like Post " << endl << endl;

	fb.LikePost("post5");
	
	cout << "Command		View Liked Posts " << endl << endl;

	cout << "----------------------------------------------------------------------" << endl << endl;

	fb.PeopleLikedPost("post5");

	cout << endl;
	cout << "Command		Comment on Post" << endl << endl;

	cout << "----------------------------------------------------------------------" << endl << endl;

	fb.CommentOnPost("post4", "Good Luck for your Result");
	fb.ViewPost("post4");


	cout << "Command		View TimeLine " << endl << endl;
	cout << "----------------------------------------------------------------------" << endl << endl;

	fb.shareMemory("post10", "Never thought I will be specialist in this field");
	fb.ViewTimeLine();

	cout << "Command		View Page " << endl << endl;
	cout << "----------------------------------------------------------------------" << endl << endl;

	fb.ViewPage("p1");





	cout << " People Liked Post:-\n\n\n";
	fb.PeopleLikedPost("post5");
	cout << endl;
	fb.SetCurrentUser("u1");
	fb.LikePost("post5");
	cout << "Amna Akram also Liked the post:-\n";

	fb.PeopleLikedPost("post5");

	cout << "Details of Post 1:\n";
	fb.ViewPost("post1");



	cout << "view home of current user: " << endl << endl;

	fb.UserTimeLine();
	//cout << " Before Adding Comment:-\n";
	//fb.ViewPost("post1");

	fb.CommentOnPost("post1", "New Comment");
	cout << " After Adding Comment:-\n";
	fb.ViewPost("post1");


	cout << " Home Page of Abdullah Nadeem:-\n";
	fb.HomePage();


}