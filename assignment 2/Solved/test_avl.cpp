#include <iostream>
#include <cstdio>
#include <signal.h>
#include "avl2.cpp"
using namespace std;

int total_values = 54;
double TreeAfterAddition[54] = {30.0,32.3,32.5,34.4,35.0,36.6,37.4,38.6,39.5,39.7,39.8,40.0,44.2,44.3,44.7,45.6,46.9,47.3,49.5,49.6,49.7,50.5,50.9,51.0,52.8,53.1,53.2,54.7,62.0,66.3,68.5,69.9,70.3,70.8,71.0,72.1,73.2,75.4,77.6,78.3,79.0,80.6,81.8,82.2,84.0,86.5,88.8,89.3,91.0,92.8,95.3,96.5,97.2,98.9};
double maxScores[5] = {98.9,97.2,96.5,95.3,92.8};
int indx = 0;
int pts = 0;
int step = 0;
template<class T>
void TraverseTree( AvLNode<T> *P,int test)
{
	if(P->left)
		TraverseTree(P->left,test);
	if(P->key == TreeAfterAddition[indx]){
        pts++;
	}
	indx++;
	if(P->right)
		TraverseTree(P->right,test);

}

void test_addition()
{
	cout<<"Testing Addition\n";
	pts = 0;
	indx = 0;
	int success = 1;
	AvL<double> B("input_avl.txt");
	step++;

	TraverseTree(B.getRoot(),1);
	if(pts < 54){
		cout << "Addition: Order of nodes not okay!!!\n";
		success = 0;
	}

	step++;
	pts = 0;
	AvLNode<double>* root = B.getRoot();
	if(root->key == 66.3)
		pts++;
	if(root->right->key == 82.2)
		pts++;
	if(root->left->key == 47.3)
		pts++;
	if(root->left->left->left->key == 35.0)
		pts++;
	if(root->left->right->right->key == 54.7)
		pts++;
	if(root->right->left->right->key == 79.0)
		pts++;
	if(root->right->right->right->right->key == 98.9)
		pts++;
	if(root->left->left->right->left->key == 39.7)
		pts++;
	if(pts < 8){
		cout << "Addition: Structure of tree not okay!!!\n";
		success = 0;

	}
	step++;

	if(success)
		cout << "Addition Test Successful\n";
}


void test_search()
{
	cout << "Testing Search\n";
	pts = 0;
	indx = 0;
	int success = 1;
	AvL<double> B("input_avl.txt");
	for (int i=0;i<total_values;i++){
		if (B.search(TreeAfterAddition[i])->key == TreeAfterAddition[i])
			pts++;
	}
	if(pts < 54){
		cout << "Search: Value returned is not okay!!!\n";
		success = 0;
	}
	step++;
	pts = 0;

	if(B.search(100.0) == NULL)
		pts++;
	if(B.search(25.5) == NULL)
		pts++;
	if(B.search(99.0) == NULL)
		pts++;
	if(B.search(95.2) == NULL)
		pts++;
	if(pts < 4){
		cout << "Search: Non Existing values found!!!\n";
		success = 0;
	}
	step++;
	if(success)
		cout << "Search Test Successful..\n";
}

void test_max()
{
    cout << "Testing getMax\n";
	pts = 0;
	indx = 0;
	int success = 1;
	AvL<double> B("input_avl.txt");
	double* maxS = B.getTopFive();
	for (int i=0; i<5; i++){
        //cout << maxS[i] << endl;
        if (maxS[i] == maxScores[i])
			pts++;
	}
	if (pts < 5){
        cout << "Max values are not correct!!!\n";
        success = 0;
	}
	step++;
	if (success)
        cout<<"Max Test Successful..\n";
}

void test_average()
{
    cout << "Testing getAverage\n";
	pts = 0;
	indx = 0;
	int success = 1;
	AvL<double> B("input_avl.txt");
	double avgS = B.getAverage();
	if ((avgS >= 61.5) && (avgS <= 61.6))
        pts++;
	if (pts < 1){
        cout << "Average values is not correct!!!\n";
        success = 0;
	}
	step++;
	if (success)
        cout<<"Average Test Successful..\n";
}

void test_display()
{
    AvL<double> B("input_avl.txt");
    B.displayAll(B.getRoot());
}
void testcases()
{
	test_addition();
	test_search();
	test_max();
	test_average();
	//test_display();
}
void signal_handler(int signum)
{
	if(step == 2)
		cout<<"Addition: Structure of Tree is not okay..\n";
	if(step == 3)
		cout<<"Search: Existing value not found..\n";
	if(step == 5)
		cout<<"Maximum: Values returned are not correct..\n";
	if(step == 6)
		cout<<"Average: Value returned was not correct..\n";

    	cout << " Failed! \n";


    	signal(SIGSEGV, signal_handler);
    	signal(SIGFPE, signal_handler);
	cout<<"Exiting...\n";
	system("PAUSE");
	exit(1);
}
int main()
{
	signal(SIGSEGV, signal_handler);
	signal(SIGFPE, signal_handler);
	cout<<"Test Cases Started!!!!\n";
	testcases();
}

