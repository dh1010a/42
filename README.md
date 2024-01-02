## LIBFT

### 1. 프로젝트 소개

42SEOUL에서는 이미 정의되어 있는 표준 함수들을 사용해 프로젝트를 진행하는 것이 금지되어 있다. 필요하다고 생각되는 함수라면 직접 구현해 사용해야 한다. 이 프로젝트를 통해 유용한 C 표준 함수들을 재구현하면서 함수의 작동 원리와 사용법, 그리고 C언어에서 데이터와 그에 필요한 메모리를 어떻게 효율적으로 관리하고 다룰 수 있는지 배울 수 있었다. 이 라이브러리의 함수 리스트는 42SEOUL에서 학습하는 기간 동안, 필요할 때 마다 꾸준히 업데이트 할 계획이다.

### 2.규칙

프로젝트는 Norm 규칙에 맞춰 작성되어야 한다.

함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단 되어서는 안 된다. 예를 들어, segmentation fault, bus error, double free 등.

필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 한다. 메모리 누수는 용납되지 않는다.

이 라이브러리는 GCC로 -Wall -Wextra -Werror 플래그를 지정하여 컴파일 된다. 그리고 Makefile은 relink 되어서는 안된다.

전역 변수는 사용할 수 없다.

복잡한 함수를 작성하기 위해 하위 함수가 필요한 경우에는, 이러한 하위 함수를 라이브러리와 함께 publishing 하지 않도록 static(정적)으로 정의해야 한다.

### 3. 함수 리스트
이 라이브러리의 함수들은 크게 세 가지 파트로 나눌 수 있다.

첫 번째는 C 표준 라이브러리인 Libc의 함수들.

두 번째는 문자열을 다루는 유용한 함수들.

세 번째는 리스트를 다루는 유용한 함수들.

Part 1. Libc functions
첫 번째 파트에서는, man에 정의되어 있는 대로 libc functions의 set을 재구현했다. 함수들은 원본과 같은 형식의 프로토타입을 선언한다. 함수의 이름 앞에는 ft_를 붙였다.

예를 들어 strlen은 -> ft_strlen.

재구현해야 하는 함수의 프로토타입의 일부는 restrict 한정자를 사용하지만, 이 키워드는 c99 표준의 일부분이기 때문에 restrict 한정자를 프로토타입에 포함시키고 -std=c99 플래그를 사용하여 컴파일 하는 것은 금지된다.

아래의 함수들을 구현했다. 이 함수들은 외부 함수들을 필요로 하지 않는다.

memset • bzero • memcpy • memccpy • memmove • memchr • memcmp • strlen • strlcpy • strlcat • strchr • strrchr • strnstr • strncmp • atoi • isalpha • isdigit • isalnum • isascii • isprint • toupper • tolower

그리고 아래의 함수들은 malloc함수를 사용하여 재구현 했다.

calloc • strdup

Part 2. Additional functions
두 번째 파트에서는, libc에 포함되있지 않거나 다른 형식으로 포함된 functions의 set을 재구현했다. 이 함수 중 일부는 구현 시 part1의 함수를 사용했다.

substr • strjoin • strtrim • split • itoa • strmapi • putchar_fd • putstr_fd • putendl_fd • putnbr_fd

Part 3. List functions
메모리와 문자열을 다루는 함수를 사용하는 것도 편리하지만, 실제 프로젝트를 진행할 때는 리스트를 다루는 함수가 훨씬 필요했다.

리스트의 요소들은 다음의 구조를 갖는다. 이 구조를 libft.h 파일에 추가했다.

typedef struct    s_list 
{ 
    void          *content; 
    struct s_list *next; 
}                 t_list;
아래의 함수들을 구현해 라이브러리에 추가했다.

ft_lstnew • ft_lstadd_front • ft_lstsize • ft_lstlast • ft_lstadd_back • ft_lstdelone • ft_lstclear • ft_lstiter • ft_lstmap


----

## ft_printf

이 프로젝트의 목적은 printf 함수를 똑같이 구현하는 것입니다. 당신은 주로 가변인자를 어떻게 사용하는지 배우게 될 것입니다.

### 1. Common Instructions
프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 있는 경우, 해당 파일/함수들은 norm 검사에 포함되며, norm error가 있을 시, 0점을 받게 될것 입니다.
함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단되어서는 안 됩니다. (예를 들어, segmentation fault, bus error, double free 등)
필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용납되지 않을 것입니다.
그 과제가 필요하다면, Makefile을 제출해야 합니다. 그것은 -Wall -Wextra -Werror 플래그를 지정하여 컴파일할 것입니다. 그리고 Makefile은 relink 되어서는 안됩니다.
Makefile은 최소한 $(NAME), all, clean, fclean, re를 포함해야 합니다.
프로젝트에서 당신의 libft를 허용한다면, 소스들과 그것과 연관된 Makefile을 연관 된 Makefile과 함께 libft폴더에 복사해야 합니다. 프로젝트의 Makefile은 Makefile 을 사용하여 라이브러리를 컴파일한 다음, 프로젝트를 컴파일해야 합니다.

### 2. Mandatory part
Program name

libftprintf.a

Turn in ﬁles

.c, /.c, *.h, /.h, Makefile
Makeﬁle

all, clean, fclean, re, bonus

External functs.

malloc, free, write, va_start, va_arg, va_copy, va_end

Libft authorized

yes

### Description
Write a library that contains ft_printf, a function that will mimic the real printf

ft_printf의 프로토타입은 int ft_printf(const char *, …); 이여야 합니다.
당신은 libc의 printf 함수를 recode해야 합니다.
원래의 printf 함수처럼 buffer 관리를 해서는 안 됩니다.
다음과 같은 conversions를 관리 할 것입니다 : cspdiuxX%
모든 conversions에서 ‘-0.*’ 플래그와 minimum field width의 조합을 관리 할 것입니다.
원래의 printf 함수와 비교될 것입니다.
