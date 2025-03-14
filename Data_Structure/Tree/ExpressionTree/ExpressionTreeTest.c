#include "ExpressionTree.h"

int main(void){
    ETNode* Root = NULL;

    char PostfixExpression[20] = "71*52-/";
    ET_BuildExpressionTree(PostfixExpression, &Root);

    // 트리 출력
    printf("Preorder ...\n");
    ET_PreorderPrintTree(Root);
    printf("\n\n");

    printf("inorder ...\n");
    ET_InorderPrintTree(Root);
    printf("\n\n");

    printf("Postorder ...\n");
    ET_PostorderPrintTree(Root);
    printf("\n\n");

    printf("Evaluation Result %f\n", ET_Evaluate(Root));

    return 0;
}