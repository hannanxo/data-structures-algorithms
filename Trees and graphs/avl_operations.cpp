#include <iostream>
using namespace std;

struct node
{
    int info;
    node *right, *left;
};

class tree
{

public:
    node *root;

    tree()
    {
        root = NULL;
    }

    void createtree(node *temp, int key)
    {
        if (root == NULL)
        {
            root = new node;
            root->info = key;
            root->left = NULL;
            root->right = NULL;
            return;
        }

        if (temp->info == key)
        {
            cout << "Same Node" << endl;
            return;
        }

        if (temp->info > key)
        {
            if (temp->left != NULL)
            {
                createtree(temp->left, key);
            }
            else
            {
                temp->left = new node;
                temp->left->info = key;
                temp->left->left = NULL;
                temp->left->right = NULL;
                return;
            }
        }

        if (temp->info < key)
        {
            if (temp->right != NULL)
            {
                createtree(temp->right, key);
            }
            else
            {
                temp->right = new node;
                temp->right->info = key;
                temp->right->left = NULL;
                temp->right->right = NULL;
                return;
            }
        }
    }

    struct node *check(node *temp, int key)
    {
        if (temp == NULL)
        {
            cout << "Tree is empty" << endl;
            return NULL;
        }

        if (temp->info == key)
        {
            //node *f = NULL;
            //f = temp;
            cout << "Node is found" << temp->info << endl;
            return temp;
        }

        if (temp->left != NULL && temp->info != key)
        {
            check(temp->left, key);
        }
        cout << temp->info << endl;

        if (temp->right != NULL && temp->info != key)
        {
            check(temp->right, key);
        }
    }

    void print(node *temp)
    {
        if (temp == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (temp->left != NULL)
            print(temp->left);

        cout << temp->info << endl;

        if (temp->right != NULL)

            print(temp->right);
    }

    void del(node *temp, int key)
    {

        if (temp == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        //Case 1: delete root
        if (temp->info == key && temp->right == NULL && temp->left == NULL)
        {
            root = NULL;
        }

        if ((temp->info == key && temp->right == NULL && temp->left != NULL) || (temp->info == key && temp->right != NULL && temp->left == NULL))
        {
            if (temp->right == NULL && temp->left != NULL)
            {
                root = temp->left;
            }
            else
            {
                root = temp->right;
            }
        }

        if (temp->info == key && temp->right != NULL && temp->left != NULL)
        {
            temp = temp->right;
            while (temp->left->left != NULL)
            {
                temp = temp->left;
            }
            root->info = temp->left->info;
            temp->left = NULL;
            delete temp->left;
        }

        //case 2:delete any node
        node *f = NULL;

        if (key < temp->info)
        {

            f = check(temp, key);
            cout << f->info;
        }
    }

    void min(node *temp)
    {
        if (temp == NULL)
        {
            cout << "No node exists" << endl;
            return;
        }

        if (temp->left->left == NULL && temp->left->right == NULL)
        {
            cout << "Third minimum is not possible" << endl;
            return;
        }

        if (temp->left != NULL && temp->left->right == NULL)
        {
            while (temp->left->left->left != NULL)
            {
                temp = temp->left;
            }
            if (temp->left->left->right != NULL)
            {
            }
            cout << "Third minimum :" << temp->info << endl;
            cout << "Second minimum :" << temp->left->info << endl;
        }
    }
};

int main()
{
    tree t;
    t.createtree(t.root, 69);
    t.createtree(t.root, 55);
    t.createtree(t.root, 44);
    t.createtree(t.root, 40);
    t.createtree(t.root, 33);
    t.createtree(t.root, 22);
    t.createtree(t.root, 99);
    t.createtree(t.root, 88);
    //t.createtree(t.root, 88);
    t.createtree(t.root, 101);
    t.createtree(t.root, 122);
    t.createtree(t.root, 87);
    t.createtree(t.root, 77);
    //cout << "Before deletion" << endl;
    //t.print(t.root);
    t.min(t.root);
    //t.check(t.root, 87);
    //t.del(t.root, 87);
    //cout << "After deletion" << endl;
    //t.print(t.root);
    return 0;
}
