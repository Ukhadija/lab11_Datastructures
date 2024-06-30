#include "Header.h"

int main()
{
	BSTree tree;
	tree.insert(1);
	tree.insert(6);
	tree.insert(3);
	tree.insert(4);
	tree.insert(23);
	tree.insert(11);
	tree.insert(7);
	Node* r = tree.getRoot();
	cout << endl << "postorder:" << endl;;
	tree.PostOrderTraversal(r);
	r= tree.removeKeys(r,r,6,11);
	//r=tree.Delete(r,1);
	cout << endl << "postorder:" << endl;;
	tree.PostOrderTraversal(r);
	//cout<<tree.leastAncestor(r, 4, 7);

	/*int* arr = new int[3];
	arr[0] = 3;
	arr[1] = 4;
	arr[2] = 7;*/
	//cout << tree.subtree(arr, 3) << endl;

	//DiagnolSum(r);
	//cout << "inorder" << endl;
	//tree.inOrderWithStack(r);
	//cout << endl << "preorder:" << endl;
	//tree.PreOrderTraversal(r);
	//cout << endl << "postorder:" << endl;;
	//tree.PostOrderTraversal(r);
	//cout << endl << "level" << endl;;
	//tree.LevelOrder(r);

	// cout << endl << tree.getMin() << endl;;


	return 0;
}