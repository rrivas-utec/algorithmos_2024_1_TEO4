#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <fstream>
#include <forward_list>

#include <algorithm>    // Algoritmos no-mutables, mutable, ordenamiento
#include <numeric>      // Algoritmos numericos
#include <functional>   // Funciones objeto predeterminadas
#include <iterator>     // Algunas ayudas de Iteradores
#include <type_traits>  // Conjunto de Traits existentes
#include <random>


bool EsPar(int item) {
    return item % 2 == 0;
}

void ejemplo_copy() {
    std::vector v1 { 1, 2, 3, 4, 5, 6};
    auto v2 = v1;
    std::vector<int> v3;
    for (auto it = v1.begin()+3; it != v1.end(); ++it)
        v3.emplace_back(*it);

    std::vector<int> v4(3);
    std::copy(v1.begin()+3, v1.end(), v4.begin());

    std::vector<int> v5;
    std::copy(v1.begin()+3, v1.end(), std::back_inserter(v5));

    std::vector<int> v_pares;
    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v_pares), EsPar);

    std::vector<int> v_impares;
    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v_impares),
                 [](auto item) { return item % 2 != 0; });
}

void ejemplo_sort() {
    std::vector<int> v1(20);
    std::iota(v1.begin(), v1.end(), 1); // Llena el vector del 1 al 20
    // Aleatorizar
    std::random_device rd;     // Random Device (Dado)
    std::mt19937 g(rd());   // Randorizador (Engine)
    std::shuffle(v1.begin(), v1.end(), g);
    // Imprimir los valores
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    // Ordenar
    std::sort(v1.begin(), v1.end());
    // Imprimir los valores
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    // Ordenar
    std::sort(v1.begin(), v1.end(), std::greater{});
    // Imprimir los valores
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    // Ordenar
    std::sort(v1.begin(), v1.end(), [](auto a, auto b) { return a < b; });
    // Imprimir los valores
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void ejemplo_accumulate() {
    std::ifstream file("datos.txt");
    if (!file.is_open()) {
        std::cout << "Archivo Inexistente\n";
        return;
    }
    std::cout << "Archivo Leido\n";
    std::list<int> ls1;
    int item;
    while (file >> item) {
        ls1.emplace_back(item);
    }
    // Imprimir los valores
    std::copy(ls1.begin(), ls1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    // Operara el contenido
    auto total_suma = std::accumulate(ls1.begin(), ls1.end(), 0);
    std::cout << total_suma << std::endl;
}

void ejemplo_accumulate_2() {
    std::ifstream file("datos.txt");
    if (!file.is_open()) {
        std::cout << "Archivo Inexistente\n";
        return;
    }
    std::cout << "Archivo Leido\n";

    std::list<int> ls1;
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(ls1));

    // Operara el contenido
    auto total_suma = std::accumulate(ls1.begin(), ls1.end(), 0);
    std::cout << total_suma << std::endl;
}

void ejemplo_accumulate_3() {
    std::ifstream file("datos.txt");
    if (!file.is_open()) {
        std::cout << "Archivo Inexistente\n";
        return;
    }
    std::cout << "Archivo Leido\n";
    // Operara el contenido
    std::cout <<
        std::accumulate(
                std::istream_iterator<int>(file),
                std::istream_iterator<int>(), 0)
            << std::endl;
}

void ejemplo_accumulate_4() {
    std::ifstream file("datos2.txt");
    if (!file.is_open()) {
        std::cout << "Archivo Inexistente\n";
        return;
    }
    std::cout << "Archivo Leido\n";
    // Operara el contenido
    std::list<int> ls1;
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(ls1));

    auto total_suma = std::accumulate(
            ls1.begin(),
            ls1.end(), 0);
    auto total_multiplicacion = std::accumulate(
            ls1.begin(),
            ls1.end(), 1, std::multiplies{});
    std::cout << total_suma << " " << total_multiplicacion << std::endl;
}


int main() {
    ejemplo_accumulate();
    ejemplo_accumulate_2();
    ejemplo_accumulate_3();
    ejemplo_accumulate_4();
//    ejemplo_sort();
    return 0;
}
