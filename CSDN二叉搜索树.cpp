    //建立二叉搜索树,左小右大
    bool insertBST(BTreeNode* &Node,int element){
        int data;
        data  =element;
        if(Node){
            if(element == Node->data){
                return false;
            } else{
                //与Node的数据比较
                if(element >Node->data){
                    return insertBST(Node->left,element);
                } else{
                    return insertBST(Node->right,element);
                }
            }
        } else{
            Node = new BTreeNode;
            Node->data = data;
            return true;
        }
    }
    //二叉搜索树查找
    BTreeNode* BSTSearch(BTreeNode *Node,int data){
        if(Node == NULL || Node->data == data){
            return Node;
        } else{
            if(data > Node->data){
                BSTSearch(Node->right,data);
            } else{
                BSTSearch(Node->left,data);
            }
        }
    }
    //二叉搜索树删除元素
    bool deleteBST(BTreeNode* &Node,int data){
        if(!Node){
            return false;
        }
        if(data == Node->data){
            //找到元素，删除元素，找到子树替换当前位置
            deleteBSTNode(Node);
            return true;
        } else if(data > Node->data){
            //元素在右子树
            deleteBST(Node->right,data);
        } else{
            //元素在左子树
            deleteBST(Node->left,data);
        }
    }
     void deleteBSTNode(BTreeNode*& Node){
        BTreeNode *node = Node;
        //若有左子树，找左子树中最大的，或者右子树中最小的，替换当前节点
        if(Node->left){
            BTreeNode *left = Node->left;
            //左子树的最右边子树的父节点
            BTreeNode *Preer = Node->left;
            while(left->right){
                Preer = left;
                left = left->right;
            }
            if(Preer != left){
                //删除pererd的右叶子
                left->left =Node->left;
                Preer->right = NULL;
            }
            Node = left;
        } else{
            Node = Node->right;
        }
        delete node;
    }

