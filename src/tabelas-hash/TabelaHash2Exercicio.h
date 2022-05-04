#include <vector>
#include<iostream>
using namespace std;

template <typename K, typename V>
class Tupla {
	private:
		K chave;
		V valor;
		Tupla* prox;
	public:
		Tupla(K c, V v){
			chave = c;
			valor = v;
			prox = NULL;
		}

		K getChave() {
			return chave;
		}

		V getValor() {
			return valor;
		}

		Tupla* getProx() {
			return prox;
		}

		void setProx(Tupla* prox) {
			Tupla::prox = prox;
		}
};

template <typename Chave, typename Valor>
class TabelaHash2{
	
	private:
		Tupla<Chave, Valor>** tabela;
		
		//tamanho atual do array
		int qtdeBuckets;
		//qtdade de elementos j� inseridos na tabela hash
		int qtdadeElementos;

		/**
		* Fun��o para inserir a tupla <c,v> na tabela.
		* 1) � preciso calcular o c�digo hash a partir da chave c.
		* 2) Depois, usamos qtdeBuckets para descobrir o �ndice 
		* dessa tupla, usando a operacao de modulo.
		* 3) Preste aten��o na aloca��o de tupla quando h� colis�es. 
		* 4) A fun��o hash �s vezes retorna valores negativos: use abs() 
		* para evitar �ndices negativos.
		* 5) Como a implementacao eh in-place, se novoElemento for false,
		* o que indica que estamos reposicionando um elemento devido
		* ao aumento do array, podemos nos deparar com duas situa��es:
		*     Situa��o 1: o elemento foi mapeado para o mesmo bucket,
		*                 independente da mudan�a do array. Nesse caso,
		*                 n�o precisamos inseri-lo em um novo bucket.
		*     Situa��o 2: o elemento foi mapeado para outro bucket. 
		*                 Nesse caso, precisamos inseri-lo em um novo 
		*                 bucket.
		* IMPORTANTE: o retorno dessa funcao indica se um elemento
		*             foi reposicionado para um novo bucket. Esse valor
		*			  ser� utilizado na fun��o para aumento do tamanho
		*			  do array. Perceba que esse retorno n�o � �til
		*			  para a fun��o p�blica inserir(Chave c, Valor v)
		**/ 
		bool inserir(Chave c, Valor v, bool novoElemento) {
			//IMPLEMENTAR
		}

		/**
		* Fun��o para aumentar o tamanho do array
		* 1) O tamanho do array (qtdeBuckets) deve ser multiplicado 
		* por 8 para que essa opera��o seja feita com pouca frequ�ncia.
		* 2) Reposicionar as tuplas, considerando que:
		*     2.1) mesmo mudando de tamanho, ela pode permanecer no 
		*	 mesmo bucket (posicao do array).
		*	 2.2) caso ela mude de posi��o, atente para a situa��o
		*		  da lista ligada, especialmente quando h� colis�es:
		*		2.2.1) esse elemento � o primeiro da lista ligada?
		*		talvez o ponteiro que fica no array precise ser 
		*		atualizado (para NULL, caso seja o �nico do bucket,
		*		ou para o elemento posterior, caso contr�rio)
		*		2.2.2) esse elemento est� no meio da lista ligada?
		*		ajuste o ponteiro prox do elemento anterior ao elemento
		*		removido
		*	Dica: voc� precisar� navegar com 2 vari�veis auxiliares,
		*		  de modo que uma esteja sempre apontando para o 
		*		  elemento anterior.
		* 3) N�o se esque�a de desalocar (delete) as tuplas que
		* voc� est� inserindo em uma nova posi��o do array.
		**/
		void aumentaArray() {
			//IMPLEMENTAR
		}

	public:

		/**
		* Construtor
		* 1) Inicializar o array de tuplas com qtdeBuckets=8.
		* 2) Lembrar de setar todas as posi��es do vetor inicializado
		*    para NULL.
		* 3) Alocar o vetor no C-Style (calloc), para que depois 
		*    consigamos usar a fun��o realloc para trabalhar com 
		*    o tamanho do vetor completamente in-place.
		**/ 
		TabelaHash2() {
			//IMPLEMENTAR
		}

		/**
		* Essa � a fun��o p�blica que nos permite inserir
		* uma tupla <c,v> na tabela. 
		* 1) Aumentamos o array caso o load_factor >=1.
		* 2) Essa fun��o pode reusar sua vers�o
		* sobrecarregada para inserir a tupla na tabela.
		* 3) Essa fun��o tamb�m incrementa a quantidade de elementos
		* na tabela (vari�vel qtdadeElementos).
		**/ 
		void inserir(Chave c, Valor v) {
			//IMPLEMENTAR
		}

		/**
		* Essa fun��o retorna o fator de carga da Tabela Hash.
		**/
		double load_factor() {
			//IMPLEMENTAR
		}
		
		/**
		* H� apenas um valor associado a uma chave.
		* Essa fun��o retorna esse valor, caso a chave exista.
		* Se a chave n�o existir a fun��o retorna NULL.
		* Lembre-se: em caso de colis�o, � preciso navegar
		* no bucket (lista ligada) para ter certeza se a chave
		* existe ou n�o.
		**/ 
		Valor getValor(Chave chave) {
			//IMPLEMENTAR	
		}

		/**
		* Essa fun��o retorna true caso a chave exista,
		* false caso contr�rio.
		* Lembre-se: em caso de colis�o, � preciso navegar
		* no bucket (lista ligada) para ter certeza se a chave
		* existe ou n�o.
		**/
		bool contemChave(Chave chave) {
			//IMPLEMENTAR
		}

		/**
		* Essa fun��o retorna um vetor com todas as chaves
		* j� inseridas na tabela.
		**/
		vector<Chave> getChaves() {
			//IMPLEMENTAR
		}

		/**
		* Essa fun��o desaloca os n�s previamente alocados, e muda
		* o tamanho do array de tuplas para 8.
		**/
		void clear() {
			//IMPLEMENTAR
		}

		/**
		* H� apenas um n� associado com uma mesma chave.
		* Essa fun��o remove esse n� da tabela, caso a chave exista.
		* Se a chave n�o existir a fun��o n�o faz nada.
		* Lembre-se: em caso de colis�o, � preciso navegar
		* no bucket (lista ligada) para ter certeza se a chave
		* existe ou n�o.
		* Dica: olhar algoritmo de remo��o em lista ligada, pois
		* ap�s a remo��o de um n� a lista precisa permanecer �ntegra,
		* ou seja, naveg�vel.
		**/
		void remover(Chave chave) {
			//IMPLEMENTAR
		}

		/**
		* Essa fun��o retorna a quantidade de elementos
		* que j� foram inseridos na Tabela Hash.
		**/
		int size() {
			return qtdadeElementos;
		}

		/**
		* Essa fun��o retorna o tamanho atual do
		* array usado para armazenar a Tabela Hash.
		**/
		int bucket_count() {
			return qtdeBuckets;
		}
};