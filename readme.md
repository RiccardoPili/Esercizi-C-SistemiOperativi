# Liste
Le liste (di interi) sono una struct di questo tipo:
```
typedef struct _node {
  int val;
  struct _node *next;
} node;
```

Scorrimento di una lista con un unico puntatore:
```
while(l != NULL) {
  ...
  l = l->next
}
```

### Puntatori prev e next
Utilizzo dei puntatori prev e next, usati ad esempio per "saltare" alcuni elementi della lista.
```
node *prev = NULL;
node *next = NULL;
node *curr = head;

...

prev = curr;
curr = curr->next;
```

### Cancellazione di nodi
Per la cancellazione dei nodi bisogna ricordarsi di usare `free` e aggiornare il puntatore del nodo precedente con `prev->next = curr->next`. Oltre questo bisogna gestire il caso in cui il nodo da eliminare sia in testa (e quindi `prev == null`).


### Inserimento di un nodo in testa
```
node *newnode = malloc(sizeof(node));
newnode->next = head;
head = newnode;
```

### Esempi di problemi ricorrenti negli esercizi su Liste
- Eliminazione di nodi: [`list_erase.c`](ex/list_erase.c), [`list_free_between.c`](ex/list_free_between.c)
- Inversione: [`list_invert.c`](ex/list_invert.c)
- Shift: [`list_shift.c`](ex/list_shift.c)
- Taglio tra indici: [`cut_list.c`](ex/cut_list.c)
- Rimozione min/max: [`list_cut_minmax.c`](ex/list_cut_minmax.c)
- Spostamento testa: [`list_head_is_max.c`](ex/list_head_is_max.c)

---

# Array e Stringhe

### Esempi di problemi ricorrenti negli esercizi su Array e Stringhe
- Estrazione di sottostringhe tra caratteri o indici: [`substring.c`](ex/substring.c), [`get_sel.c`](ex/get_sel.c), [`strtrim.c`](ex/strtrim.c)
- Ricerca del minimo e massimo: [`minmax_by_age.c`](ex/minmax_by_age.c), [`list_cut_minmax.c`](ex/list_cut_minmax.c)
- Ricerca della parola più lunga in una stringa: [`longest_word.c`](longest_word.c)
- Utilizzo di struct complesse: [`vec_list_cut_leq.c`](ex/vec_list_cut_leq.c)

### Allocazione della memoria
Si usa la funzione `malloc(size)` ogni volta che bisogna creare una nuova stringa (ad esempio per restituire un risultato) o un nuovo array.

Si usa `realloc(ptr, newsize)` quando bisogna aumentare o ridurre la dimensione di una stringa o array già allocato, ad esempio se costruisci una stringa carattere per carattere e non sai in anticipo quanto sarà lunga.

## Libreria <string.h>
La libreria `<string.h>` fornisce delle funzioni che possono essere utili per gli esercizi di programmazione su liste oppure sulle stringhe (se non è specificato che non si possono usare). Per tutte le funzioni comando dal terminale `man string`.

- `strlen(s)` – lunghezza della stringa
- `strcpy(dest, src)` – copia stringa
- `strncpy(dest, src, n)` – copia n caratteri
- `strcat(dest, src)` – concatena stringhe
- `strcmp(s1, s2)` – confronto stringhe
- `strchr(s, c)` – cerca carattere
- `strstr(s, sub)` – cerca sottostringa
- `strtok(s, delim)` – suddivide in token