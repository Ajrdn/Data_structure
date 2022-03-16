#include<stdio.h>

void preorder( char *t, int n, int size ){
	if (n > size || (t[n] == 0))
		return ;
	printf("%c ", t[n]);
	preorder(t, 2 * n, size);
	preorder(t, 2 * n + 1, size);
}
void inorder( char *t, int n, int size ){
	if (n > size || (t[n] == 0))
		return ;
	inorder(t, 2 * n, size);
	printf("%c ", t[n]);
	inorder(t, 2 * n + 1, size);
}
void postorder( char *t, int n, int size ){
	if (n > size || (t[n] == 0))
		return ;
	postorder(t, 2 * n, size);
	postorder(t, 2 * n + 1, size);
	printf("%c ", t[n]);
}
int main(){
	char tree[]= { 0,'A', 'B', 'C', 'D', 'E', 'F', 'G', 0, 0,'H', 'I', 0, 'J', 'K', 'L'};
	int size=16;
	printf("\n<<ÀüÀ§ Å½»ö>>\n");
	preorder( tree, 1, size );
	printf("\n<<ÁßÀ§ Å½»ö>>\n");
	inorder( tree, 1, size );
	printf("\n<<ÈÄÀ§ Å½»ö>>\n");
  postorder( tree, 1, size );
	
}