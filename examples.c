#include <stdio.h>
#include <stdlib.h>

// длина строки
int slen(const char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    count++;
  }
  return ++count;
}

// сравнение без учёта регистра
int scmp_low(char *s1, char *s2) {
  char *lower1 = malloc(sizeof(char) * (slen(s1) + 1));
  char *lower2 = malloc(sizeof(char) * (slen(s1) + 1));
  for (int i = 0; i < slen(s1); i++) {
    lower1[i] = toLow(s1[i]);
  }
  for (int i = 0; i < slen(s2); i++) {
    lower2[i] = toLow(s2[i]);
  }
  return scmp(lower1, lower2);
}

// нахождение префикса строки, не содержащего запрещённые символы
char *prefixRestricted(char *str, char *alphabet) {
  char *prefix = malloc(sizeof(char) * (slen(str) + 1));
  for (int i = 0; i < slen(str); i++) {
    int exit = 0;
    for (int j = 0; j < slen(alphabet); j++) {
      if (str[i] == alphabet[j]) {
        exit++;
        break;
      }
    }
    if (exit != 0) {
      break;
    }
    prefix[i] = str[i];
    counter++;
  }
  return prefix;
}

// нахождение префикса строки, содержащего только допустимые символы
char *prefixOnlyAlpha(char *str, char *alphabet) {
  char *prefix = malloc(sizeof(char) * (slen(str) + 1));
  int counter = 0;
  for (int i = 0; i < slen(str); i++) {
    int exit = 0;
    for (int j = 0; j < slen(alphabet); j++) {
      if (str[i] != alphabet[j]) {
        exit++;
        break;
      }
    }
    if (exit != 0) {
      break;
    }
    prefix[counter] = str[i];
    counter++;
  }
  return prefix;
}

// копирование строк
char *scpy(const char *src, char *des) {
  int i;
  for (i = 0; src[i] != 0; i++) {
    des[i] = src[i];
  }
  des[i] = 0;
  return des;
}

// поиск вхождения одной строки в другую
char *sstr(const char *s1, const char *s2) {
  if (*s2 == '\0') {
    return s1;
  }
  char *ptr;
  for (int i = 0; i < slen(s1); i++) {
    if (*(s1 + i) == *s2) {
      ptr = sstr(s1 + i + 1, s2 + 1);
      return (ptr) ? ptr - 1 : NULL;
    }
  }
  return NULL;
}

// строка в число
int n_atoi(char *str) {
  int result = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    result = result * 10 + str[i] - '0';
  }
  return result;
}

// число в строку
char *n_itoa(int num) {
  char buf[16];
  sprintf(buf, "%d", num);
  return buf;
}

// в нижний регистр
char toLow(char c) { return ('a' + (c - 'A')); }

// в верхний регистр
char toUp(char c) { return ('A' + (c - 'a')); }

char *Camel_to_snake(char *str) {
  int size = slen(str) + 1;
  char *buf = malloc(sizeof(char) * size);
  buf[0] = toLow(str[0]);
  for (int i = 1; i < slen(str); i++) { // CamelNow -> camel_now
    if (str[i] >= 'A' && str[i] <= 'Z') {
      size += 2;
      buf = realloc(buf, sizeof(char) * size);
      buf[i] = '_';
      buf[i + 1] = toLow(str[i]);
      i++;
    } else {
      buf[i] = str[i];
    }
  }
  return buf;
}

char *snake_to_Camel(char *str) {
  char *buf = str;
  buf[0] = toUp(str[0]);
  for (int i = 1; i < slen(str); i++) {
    if (str[i - 1] == '_') {
      buf[i - 1] = toUp(str[i]);
      buf[i] = str[i + 1];
      i++;
    } else {
      buf[i] = str[i];
    }
  }
  return buf;
}

// подсчёт количества символов строки, входящих в заданный алфавит
int alphabetCharEncounter(char *str, const char *alphabet) {
  int result = 0;
  for (int i = 0; i < slen(str); i++) {
    for (int j = 0; j < slen(alphabet); j++) {
      if (str[i] == alphabet[j]) {
        result++;
      }
    }
  }
  return result;
}

// сравнение строк по алфавиту (а = 1, b = 2, c = 3 ... etc.)
int compareAlphabetically(const char *s1, const char *s2) {
  int s1_power = 0, s2_power = 0;
  for (int i = 0; i < slen(s1); i++) {
    s1_power += s1[i] - 'a' + 1;
  }
  for (int i = 0; i < slen(s2); i++) {
    s2_power += s2[i] - 'a' + 1;
  }
  return s1_power - s2_power;
}

// вставка одной строки в конец другой (конкатенация)
char *scat(char *dest, const char *src) {
  char *end = dest + slen(dest) - 1;
  while (*src != '\0') {
    *end++ = *src++;
  }
  *end = '\0';
  return dest;
}

// поиск вхождения символа в строку
char *schr(const char *s, const char c) {
  while (*s && *s != c) {
    ++s;
  }
  return (*s) ? (char *)s : NULL;
}

// сравнение строк с учётом регистров
int scmp(const char *s1, const char *s2) {
  char c1, c2;
  while (1) {
    c1 = *s1++;
    c2 = *s2++;
    if (c1 > c2) {
      return 1;
    } else if (!c1) {
      break;
    } else {
      return -1;
    }
  }
  return 0;
}

char *stok(char *str, const char *delim) {
  static char *next;
  if (str) {
    next = str;
    while (*next && schr(delim, *next)) {
      *next++ = '\0';
    }
  }
  if (!*next) {
    return NULL;
  }
  str = next;
  while (*next && !schr(delim, *next)) {
    ++next;
  }
  while (*next && schr(delim, *next)) {
    *next++ = '\0';
  }
  return str;
}

// проверка валидности IP-адреса узла
int checkIP(char *in) {
  char *ip = in;
  char *token = stok(ip, ".");
  while (token != NULL) {
    int num = atoi(token);
    if (num < 0 || num > 255) {
      return -1;
    }
    token = stok(NULL, ".");
  }
  return 0;
}

// сумма чётных чисел в массиве
int sumEven(int *arr, int size) {
  int res = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      res += arr[i];
    }
  }
  return res;
}

// сумма нечётных чисел в массиве
int sumOdd(int *arr, int size) {
  int res = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 1) {
      res += arr[i];
    }
  }
  return res;
}
