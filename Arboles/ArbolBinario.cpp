/*
	IMPLEMENTACIÓN DE UN ÁRBOL BINARIO DE BÚSQUEDA
	
	+ La función ELIMINAR del video no funcionaba, el detalle se ha corregido
	
*/

#include <iostream>
#include <string>
using namespace std;

struct BinarySearchTree {
	int data;
	BinarySearchTree* leftChild;
	BinarySearchTree* rightChild;
};

BinarySearchTree* getNode(int value){
	BinarySearchTree *node = new BinarySearchTree();
	node->data = value;
	node->leftChild = node->rightChild = NULL;
	return node;
}

BinarySearchTree* insert(BinarySearchTree* root, int value){
	if(root == NULL){
		return getNode(value);
	}else if (root->data == value) {
    cout << "\n\n\tERROR: El valor " << value << " existe en el árbol";
	} 
 	else if(value < root->data){
		root->leftChild = insert(root->leftChild, value);
	} else {
		root->rightChild = insert(root->rightChild, value);
	}
	return root;
}

BinarySearchTree* search(BinarySearchTree* root, int value) {
    if (root == NULL) {
        cout << "\n\n\tERROR: El valor " << value << " no existe en el árbol";
        return NULL;
    } else if (root->data == value) {
        return root;
    } else if (value < root->data) {
        return search(root->leftChild, value);
    } else {
        return search(root->rightChild, value);
    }
}

void update(BinarySearchTree* root, int value, int newValue) {
    BinarySearchTree* node = search(root, value);
    if (node != NULL) {
        node->data = newValue;
    } else {
        cout << "\n\n\tERROR: No se puede actualizar. El valor " << value << " no existe en el árbol.";
    }
}


void preOrder(BinarySearchTree* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}


void inOrder(BinarySearchTree* root){
	if(root == NULL)
		return;
	inOrder(root->leftChild);
	cout<<root->data;
	inOrder(root->rightChild);
}

void postOrder(BinarySearchTree* root){
	if(root == NULL)
		return;
	postOrder(root->leftChild);
	postOrder(root->rightChild);
	cout<<root->data;
}

BinarySearchTree* remove(BinarySearchTree* root, int value){
	if(root == NULL){
		cout<<"El elemento no existe";
		return NULL;
	}
	else if(value < root->data)
		root->leftChild = remove(root->leftChild, value);
	else if(value > root->data)
		root->rightChild = remove(root->rightChild, value);
	else {
		if(root->leftChild==NULL && root->rightChild==NULL)
			root = NULL;
		else if(root->leftChild == NULL)
			root = root->rightChild;
		else if(root->rightChild == NULL)
			root = root->leftChild;
		else {
			BinarySearchTree* explorer = root->rightChild;
			while(explorer->leftChild)
				explorer = explorer->leftChild;
			root->data = explorer->data;
			root->rightChild = remove(root->rightChild, explorer->data);
		}
	}
	return root;
}

void destroyTree(BinarySearchTree* root) {
    if (root == NULL)
        return;
    destroyTree(root->leftChild);
    destroyTree(root->rightChild);
    delete root;
}


int main(){
	BinarySearchTree* TREE = NULL;
	TREE = insert(TREE, 5);
	insert(TREE, 8);
	insert(TREE, 3);
	insert(TREE, 15);
	insert(TREE, 1);
	TREE = remove(TREE, 6);
	printf("\n");
	preOrder(TREE);
	destroyTree(TREE);
	return 0;
}