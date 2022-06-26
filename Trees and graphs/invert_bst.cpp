#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

class bst
{

private:
    node *root;

public:
    bst()
    {
        root = NULL;
    }

    node *createnode(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
    }

    node *add(node *iter, int data)
    {
        if (iter == NULL)
        {
            if (root == NULL)
            {
                return root = createnode(data);
            }

            return createnode(data);
        }

        if (data < iter->data)
            iter->left = add(iter->left, data);
        else if (data > iter->data)
            iter->right = add(iter->right, data);

        return iter;
    }

    node *getroot()
    {
        return root;
    }

    void display(node *iter)
    {
        if (iter == NULL)
        {
            return;
        }

        display(iter->left);
        cout << iter->data << " ";
        display(iter->right);
    }

    int depth(node *iter)
    {
        if (!iter->left && !iter->right)
            return 1;

        if (!iter->left)
            return depth(iter->right) + 1;

        if (!iter->right)
            return depth(iter->left) + 1;

        int leftsubtree = depth(iter->left) + 1;
        int rightsubtree = depth(iter->right) + 1;

        if (leftsubtree > rightsubtree)
            return leftsubtree;

        return rightsubtree;
    }
    int diameterOfBinaryTree(node *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            /* compute the depth of each subtree */
            int lDepth = depth(root->left);
            int rDepth = depth(root->right);

            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
        node *invert(node * iter)
        {
            if (!iter)
                return NULL;
            invert(iter->left);
            invert(iter->right);
            swap(iter->left, iter->right);
            return iter;
        }
    };

    int main()
    {
        bst b;
        b.add(b.getroot(), 13);
        b.add(b.getroot(), 10);
        b.add(b.getroot(), 15);
        b.add(b.getroot(), 9);
        b.add(b.getroot(), 22);
        b.add(b.getroot(), 26);

        b.display(b.getroot());
        cout << "Maximum depth " << b.depth(b.getroot()) << endl;
        cout << "Maximum Diameter "<<b.diameterOfBinaryTree(b.getroot())<<endl;
        b.invert(b.getroot());
        b.display(b.getroot());
        return 0;
    }