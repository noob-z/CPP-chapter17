#include "define_declaration_17.h"
#include "list.h"
void showmovies(Item item);//显示内容；

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void films1(void)
{
	struct film movies[FMAX];
	int i = 0;
	int j;

	puts("Enter first movie title:");
	while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d",&movies[i++].rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
	}
	if (i == 0)
		puts("No data entered. ");
	else
		puts("Here is the movie list:");

	for (j = 0; j < i; j++)
		printf("Movie: %s Rating: %d\n", movies[j].title, movies[j].rating);
	printf("Bye.\n");
}

void films2(void)
{
	struct film2 * head = NULL;
	struct film2 * prev, * current;
	char input[TTSIZE];
	puts("Ente fires movie titles:");

	while (s_gets(input, TTSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film2 *)malloc(sizeof(struct film2));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stp:)");
		prev = current;
	}

	if (head == NULL)
		printf("No data entered.\n");
	else
		printf("Here is the movie list:\n");
	current = head;
	while (current != NULL)
	{
		printf("Movies : %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}

	current = head;
	while (head != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
	puts("Bye!");
}

void films3(void)
{
	List movies;
	Item temp;

	/*初始化*/
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr,"No memory available! Bye!\n");
		exit(1);
	}

	/*获取用户输入并储存*/
	puts("Ente first movie title:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr,"Problem allocating memory");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list now full.");
			break;
		}
		puts("Enter next movie title(empty line to stop):");
	}
	/*显示    */
	if (ListIsEmpty(&movies))
		printf("No data entered.");
	else
	{
		printf("Here is the movie list:\n");
		Traverse(&movies, showmovies);
	}
	printf("You entered %d movies.\n", ListItemCount(&movies));

	/*清理     */
	EmptyTheList(&movies);
	printf("Bye!\n");
}

void showmovies(Item item)
{
	printf("Movie: %s Rating: %d\n", item.title, item.rating);
}