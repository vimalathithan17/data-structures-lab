#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *left, *right;
};
typedef struct Node node;
node *create(int data);
node *insert(node *root, int data);
void display_in_order(node *root);
void display_pre_order(node *root);
void display_post_order(node *root);
int height(node *root);
int diameter(node *root);
node *delete(node *root, int val);
int depth(node *root, int value);
void main() {
  int size = 10;
  int arr[] = {30, 40, 24, 58, 48, 26, 11, 13};
  int i;
  node *root = NULL;
  for (i = 0; i < 8; i++) {
    root = insert(root, arr[i]);
  }
  printf("ino:");
  display_in_order(root);
  printf("\n pre: ");
  display_pre_order(root);
  printf("\n post: ");
  display_post_order(root);
  printf("\nheight:%d", height(root));
  printf("\ndiameter:%d", diameter(root));
  printf("\ndepth:%d", depth(root, 1));
}
node *create(int data) {
  node *n = (node *)calloc(1, sizeof(node));
  n->data = data;
  n->right = NULL;
  n->left = NULL;
  return n;
}
node *insert(node *root, int data) {
  if (root == NULL) {
    return create(data);
  } else {
    if (data < root->data) {
      root->left = insert(root->left, data);
    } else {
      root->right = insert(root->right, data);
    }
    return root;
  }
}
void display_in_order(node *root) {
  if (root == NULL) {
    return;

  }
  /*
  else if(root->left==NULL && root->right==NULL){
          printf("%d ",root->data);
  }*/
  else {
    display_in_order(root->left);
    printf("%d ", root->data);
    display_in_order(root->right);
  }
}
void display_pre_order(node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  display_pre_order(root->left);
  display_pre_order(root->right);
}
void display_post_order(node *root) {
  if (root == NULL) {
    return;
  }
  display_post_order(root->left);
  display_post_order(root->right);
  printf("%d ", root->data);
  /*
  if (root!=NULL)
  {
          display_post_order(root->left);
          display_post_order(root->right);
          printf("%d ",root->data);
  }
  */
}
int height(node *root) {
  if (root == NULL) {
    return -1;
  }
  int left_height = height(root->left);
  int right_height = height(root->right);
  if (left_height > right_height) {
    return left_height + 1;
  }
  return right_height + 1;
}
int diameter(node *root) {
  int left_height = height(root->left);
  int right_height = height(root->right);
  return left_height + right_height + 3;
}

int depth(node *root, int value) {
  int depth_value;
  if (root == NULL) {
    return -1;
  } else if (root->data == value) {
    return 0;
  } else if (value < root->data) {
    depth_value = depth(root->left, value);
  } else if (value > root->data) {
    depth_value = depth(root->right, value);
  }
  if (depth_value == -1) {
    return -1;
  }
  return depth_value + 1;
}

node *delete(node *root, int val) {
  if (root == NULL) {
    return NULL;
  } else if (val < root->data) {
    root->left = delete (root->left, val);
    return root;
  } else if (root->data < val) {
    root->right = delete (root->right, val);
    return root;
  } else if (root->data == val) {
    node *temp = NULL;
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left != NULL && root->right == NULL) {
      temp = root->left;
      free(root);
      return temp;
    } else if (root->right != NULL && root->left == NULL) {
      temp = root->right;
      free(root);
      return temp;
    } else if (root->right != NULL && root->left != NULL) {
      node *parent = root, *child = root->right;
      while (child->left != NULL) {
        parent = child;
        child = child->left;
      }
      root->data = child->data;
      parent->left = child->right;
      free(child);
      return root;
    }
  }
}
