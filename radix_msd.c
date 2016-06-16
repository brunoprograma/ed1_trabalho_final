// função para encontrar o valor inteiro correspondente ao caractere
int charAt(char vetor[], int pos) {
	if (pos < strlen(vetor))
    	return (int) vetor[pos];
    return -1;
}

// TpContato é uma estrutura que guarda um vetor char de 40 posições chamado "nome"
// "temp" é um vtor auxiliar com o mesmo tamanho de "a", "lo" é a posição inicial e
// "hi" é a posição final. "d" é a posição do caractere na palavra e "N" o tamanho do vetor
// "count" é o vetor de contagem com 256+2 posições para controlar os limites de "lo" e "hi"
// para chamar a função recursivamente somente nos limites necessários
void _radixSortMSD(TpContato a[], TpContato temp[], int lo, int hi, int d, int N) {
	int i, r, count[ASCII+2] = {0};
	
	if (hi <= lo) return;
	
	// povoa o vetor de contagem
	for (i = lo; i <= hi; i++)
		count[charAt(a[i].nome, d) + 2]++;
	// soma as posições para definir os limites
	for (r = 0; r < ASCII+1; r++)
		count[r+1] += count[r];
	// povoa o vetor auxiliar
	for (i = lo; i <= hi; i++)
		temp[count[charAt(a[i].nome, d) + 1]++] = a[i];
	// copia de volta do vetor auxiliar para o vetor "a"
	for (i = lo; i <= hi; i++)
		a[i] = temp[i - lo];
	// chama a função recursivamente dos conjuntos já ordenados parcialmente
	for (r = 0; r < ASCII; r++) {
		_radixSortMSD(a, temp, lo + count[r], lo + count[r+1] - 1, d+1, N);
	}
}

void radixSortMSD(TpContato a[], int N) {
    TpContato temp[N];

    _radixSortMSD(a, temp, 0, N - 1, 0, N);
}
