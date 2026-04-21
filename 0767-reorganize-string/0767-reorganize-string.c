typedef struct {
    char ch;
    int freq;
} Node;

void swap(Node* a, Node* b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(Node* heap, int size, int i) {
    while (1) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && heap[l].freq > heap[largest].freq)
            largest = l;
        if (r < size && heap[r].freq > heap[largest].freq)
            largest = r;

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
}

void heapifyUp(Node* heap, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].freq < heap[i].freq) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void push(Node* heap, int* size, Node val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

Node pop(Node* heap, int* size) {
    Node top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return top;
}

char* reorganizeString(char* s) {
    int freq[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > (n + 1) / 2)
            return "";
    }

    Node heap[26];
    int size = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            Node node = {'a' + i, freq[i]};
            push(heap, &size, node);
        }
    }

    char* result = (char*)malloc(sizeof(char) * (n + 1));
    int idx = 0;

    while (size > 1) {
        Node first = pop(heap, &size);
        Node second = pop(heap, &size);

        result[idx++] = first.ch;
        result[idx++] = second.ch;

        first.freq--;
        second.freq--;

        if (first.freq > 0) push(heap, &size, first);
        if (second.freq > 0) push(heap, &size, second);
    }

    if (size == 1) {
        Node last = pop(heap, &size);
        result[idx++] = last.ch;
    }

    result[idx] = '\0';
    return result;
}