    //��������������,��С�Ҵ�
    bool insertBST(BTreeNode* &Node,int element){
        int data;
        data  =element;
        if(Node){
            if(element == Node->data){
                return false;
            } else{
                //��Node�����ݱȽ�
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
    //��������������
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
    //����������ɾ��Ԫ��
    bool deleteBST(BTreeNode* &Node,int data){
        if(!Node){
            return false;
        }
        if(data == Node->data){
            //�ҵ�Ԫ�أ�ɾ��Ԫ�أ��ҵ������滻��ǰλ��
            deleteBSTNode(Node);
            return true;
        } else if(data > Node->data){
            //Ԫ����������
            deleteBST(Node->right,data);
        } else{
            //Ԫ����������
            deleteBST(Node->left,data);
        }
    }
     void deleteBSTNode(BTreeNode*& Node){
        BTreeNode *node = Node;
        //�������������������������ģ���������������С�ģ��滻��ǰ�ڵ�
        if(Node->left){
            BTreeNode *left = Node->left;
            //�����������ұ������ĸ��ڵ�
            BTreeNode *Preer = Node->left;
            while(left->right){
                Preer = left;
                left = left->right;
            }
            if(Preer != left){
                //ɾ��pererd����Ҷ��
                left->left =Node->left;
                Preer->right = NULL;
            }
            Node = left;
        } else{
            Node = Node->right;
        }
        delete node;
    }

