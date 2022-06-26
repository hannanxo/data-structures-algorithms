#include <iostream>
using namespace std;

class BST
{

    struct node
    {
        int data;
        node *left;
        node *right;
    };

public:
    node *root;
    node *makeEmpty(node *t)
    {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node *insert(int x, node *t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node *findMin(node *t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node *findMax(node *t)
    {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node *remove(int x, node *t)
    {
        node *temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node *t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node *find(node *t, int x)
    {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        root = makeEmpty(root);
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
    node *getroot()
    {
        return root;
    }

    int min(node *iter, int mini)
    {

        if (!iter->left && !iter->right)
        {
            if (mini == 0)
            {
                mini = iter->data;
                return mini;
                //cout << "MINI" << mini << endl;
            }

            if (mini > iter->data)
            {
                mini = iter->data;
                return mini;
                //cout << mini << endl;
            }
        }
        if (iter->left)
            min(iter->left, mini);
        if (iter->right)
            min(iter->right, mini);
    }
    int toplevel = -1;
    bool checklevel(node *root, int level, int leafLevel)
    {
         
        cout << "Level : " << level << endl;
        if (!root->left && !root->right)
        {
            if (toplevel == -1)
            {
                toplevel = level;
                return true;
            }
            else if (level == toplevel)
                return true;
            else
                return false;
        }
        int leftr = true;
        int rightr = true;

        if (root->left)
            leftr = checklevel(root->left, level + 1, leafLevel);

        if (root->right)
            rightr = checklevel(root->right, level + 1, leafLevel);
        cout << "Left : " << leftr << endl;
        cout << "Right : " << rightr << endl;
        if (!rightr || !leftr)
            return false;
        return true;
    }

    int height(node *root,int level,int perm)
    {
        if(!root)
            return 0;

        if(!root->left && !root->right)
         {   if(!perm)
                perm=level;
                return perm;

            if(perm<level)
               {
                return level;
               }
         }
            
            int left=height(root->left,level+1,perm);
            int right=height(root->right,level+1,perm);
            
            cout<<"left"<<left<<"right"<<right<<endl;
            if(left>right)
                return left;
            else
                return right;
            cout<<"llllll";
    }           
    bool checker()
    {
        if (!root)
            return true;
        return checklevel(root, 0, 0);
    }

    void search(int x)
    {
        root = find(root, x);
    }
};

int main()
{
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(13);
    //t.insert(24);
    t.insert(22);
    t.insert(21);
    t.display();
    cout << "0 means level is diff 1 means same level : " << t.checker();
    cout << "Minimum : " << t.min(t.getroot(), 0)<<endl;
    cout << "Height : "<<t.height(t.getroot(),0,0);
    return 0;
}