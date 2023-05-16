#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct BTreeNode{
    int data = 0;
    BTreeNode *left;
    BTreeNode *right;
};
class BTree{
public:
    BTree(){
    }
    //������Ҫע�⣬��������ָ�����͵ģ��ڵ㱾�����һ��ָ�룺*node��������Ҫ����ָ����ܸı������������
    void create(BTreeNode* &Node){
        int data;
        cin >> data;
        if(data){
            Node = new BTreeNode;
            Node->data = data;
            //cout<<"data:"<<data<<endl;
            create(Node->left);
            create(Node->right);
        } else{
            Node=NULL;
        }
    }
    //���㴴��������
    void levelCreate(BTreeNode* &Node)
	{
        queue <BTreeNode*> que;
        int data;
        cin>>data;
        if(data){
            Node = new BTreeNode;
            Node->data = data;
            que.push(Node);
        } else{
            Node = NULL;
            return;
        }
        while(!que.empty()){
            BTreeNode *node = que.front();
            que.pop();
            //�����������
            cin>>data;
            if(data){
                node->left = new BTreeNode;
                node->left->data = data;
                que.push(node->left);
            } else{
                node->left = NULL;
            }
            //�����ұ�����
            cin >>data;
            if(data){
                node->right = new BTreeNode;
                node->right->data = data;
                que.push(node->right);
            } else{
                node->right = NULL;
            }
        }
    }
    //1 2 3 4 5 6 0 0 0 7 8 0 9 0 0 0 0 0 0
    void clear(BTreeNode*& Node){
        BTreeNode *p = Node;
        if(p != NULL){
            clear(Node->left);
            clear(Node->right);
            delete p;
        }
    }
    //ǰ�����(������)
    void preorderTree(BTreeNode* Node){
        if(Node!=NULL){
            cout<<Node->data<<" ,";
            preorderTree(Node->left);
            preorderTree(Node->right);
        }
    }
    //ǰ������ǵݹ�д��
    void NnredursionPreorder(BTreeNode* Node){
        stack<BTreeNode*> node;
        node.push(Node);
        BTreeNode *pNode = Node;
        while(pNode != NULL || !node.empty()){
            //1���Ȱѽڵ��ӡ��������ջ�����ڵ��������Ϊ��ǰ�Ľڵ�
            //2�����ڵ㲻Ϊ�ջ���ջ��Ϊ�գ���ȡ��ջ����
            if(pNode != NULL){

                cout<<pNode->data<<" ";
                node.push(pNode);
                pNode = pNode->left;
            } else{
                BTreeNode *treeNode = node.top();
                node.pop();
                pNode = pNode->right;

            }
        }
    }

    //�������(������)
    void inorderTree(BTreeNode* Node){
        if(Node != NULL){
            inorderTree(Node->left);
            cout<<Node->data<<" ,";
            inorderTree(Node->right);
        }
    }

    //��������������У�
    void postorderTree(BTreeNode* Node){
        if(Node != NULL){
            postorderTree(Node->left);
            postorderTree(Node->right);
            cout<<Node->data<<" ,";
        }
    }
    //�������
    void levelTree(BTreeNode *Node){
        queue<BTreeNode*> que;
        if(Node == NULL) return;
        else{
            que.push(Node);
            while(!que.empty()){
                BTreeNode *node = que.front();
                cout<<node->data<<" ";
                que.pop();
                if(node->left != NULL){
                    que.push(node->left);
                }
                if(node->right!=NULL){
                    que.push(node->right);
                }
            }
        }
    }
    //���������
    int depthOfTree(BTreeNode* Node){
        if(Node){
            return max(depthOfTree(Node->left),depthOfTree(Node->right))+1;
        } else{
            return 0;
        }
    }
    //���ؽڵ�����Ŀ
    int getNodeNum(BTreeNode* Node){
        if(Node){
            return 1+getNodeNum(Node->left)+getNodeNum(Node->right);
        } else{
            return 0;
        }
    }
    //����Ҷ�ӽڵ�
    int getLeafNum(BTreeNode* Node){
        if(!Node){
            return 0;
        } else if(Node->left == NULL && Node->right == NULL){
            return 1;
        } else{
            return getLeafNum(Node->left)+getLeafNum(Node->right);
        }
    }
};
int main(){
    BTree tree;
    BTreeNode *root;
    //tree.create(root);
    tree.levelCreate(root);
    cout<<"pre :";
    tree.preorderTree(root);
    cout<<endl;
    cout<<"in  :";
    tree.inorderTree(root);
    cout<<endl;
    cout<<"post:";
    tree.postorderTree(root);
    cout<<endl;
    cout<<"level:";
    tree.levelTree(root);
    cout<<endl;
    cout<<"NodeNum:"<<tree.getNodeNum(root)<<",depth:"<<tree.depthOfTree(root)<<",leaf:"<<tree.getLeafNum(root)<<endl;


    tree.clear(root);
    return 0;
}

