
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

// Función para convertir el tiempo en formato "ddhh:mm" a minutos desde el día 0
int time_to_minutes(const string& time_str) {
    int days, hours, minutes;
    char d;
    sscanf(time_str.c_str(), "%dd%d:%d", &days, &hours, &minutes);
    return days * 1440 + hours * 60 + minutes;
}

// Estructura para representar un vuelo
struct Flight {
    int dep_time;   // Tiempo de salida en minutos
    int arr_time;   // Tiempo de llegada en minutos
    int dep_airport; // ID del aeropuerto de salida
    int arr_airport; // ID del aeropuerto de llegada
};

// Comparador para ordenar vuelos por tiempo de salida
bool flight_cmp(const Flight& a, const Flight& b) {
    return a.dep_time < b.dep_time;
}

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> airport_to_id;
    int id_counter = 0;

    vector<Flight> flights(n);
    vector<vector<Flight>> airport_flights; // Lista de vuelos salientes por aeropuerto

    // Leer vuelos y asignar IDs únicos a los aeropuertos
    for (int i = 0; i < n; ++i) {
        string s_i, dep_time_str, t_i, arr_time_str;
        cin >> s_i >> dep_time_str >> t_i >> arr_time_str;

        if (airport_to_id.find(s_i) == airport_to_id.end()) {
            airport_to_id[s_i] = id_counter++;
            airport_flights.emplace_back(); // Añadir una lista para este aeropuerto
        }
        if (airport_to_id.find(t_i) == airport_to_id.end()) {
            airport_to_id[t_i] = id_counter++;
            airport_flights.emplace_back(); // Añadir una lista para este aeropuerto
        }

        int dep_airport = airport_to_id[s_i];
        int arr_airport = airport_to_id[t_i];
        int dep_time = time_to_minutes(dep_time_str);
        int arr_time = time_to_minutes(arr_time_str);

        Flight flight = {dep_time, arr_time, dep_airport, arr_airport};
        flights[i] = flight;
        airport_flights[dep_airport].push_back(flight);
    }

    // Ordenar los vuelos salientes de cada aeropuerto por tiempo de salida
    for (auto& flights_list : airport_flights) {
        sort(flights_list.begin(), flights_list.end(), flight_cmp);
    }

    int m;
    cin >> m;
    vector<int> itinerary_indices(m);
    for (int i = 0; i < m; ++i) {
        cin >> itinerary_indices[i];
        --itinerary_indices[i]; // Ajustar índice a base 0
    }

    // Construir el itinerario de vuelos
    vector<Flight> itinerary_flights(m);
    for (int i = 0; i < m; ++i) {
        itinerary_flights[i] = flights[itinerary_indices[i]];
    }

    // Obtener el tiempo de llegada original al destino
    int original_arrival_time = itinerary_flights.back().arr_time;
    int destination_airport = itinerary_flights.back().arr_airport;

    int max_delay = 0;
    bool stranded = false;

    // Para cada posible punto de cancelación en el itinerario
    for (int i = 0; i < m; ++i) {
        // Punto de inicio: aeropuerto y tiempo de salida del vuelo cancelado
        int start_airport = itinerary_flights[i].dep_airport;
        int start_time = itinerary_flights[i].dep_time;

        // Inicializar el tiempo de llegada más temprano para cada aeropuerto
        vector<int> earliest_arrival(id_counter, INT_MAX);
        earliest_arrival[start_airport] = start_time;

        // Cola de prioridad para seleccionar el siguiente aeropuerto a procesar
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.emplace(start_time, start_airport);

        while (!heap.empty()) {
            auto [current_time, u] = heap.top();
            heap.pop();

            if (current_time > earliest_arrival[u]) {
                continue;
            }

            // Iterar sobre los vuelos salientes del aeropuerto actual
            auto& flights_list = airport_flights[u];
            // Buscar el primer vuelo que sale no antes que current_time
            auto it = lower_bound(flights_list.begin(), flights_list.end(), Flight{current_time, 0, 0, 0}, flight_cmp);

            for (; it != flights_list.end(); ++it) {
                int dep_time = it->dep_time;
                int arr_time = it->arr_time;
                int v = it->arr_airport;

                if (dep_time < current_time) {
                    continue;
                }
                if (earliest_arrival[v] > arr_time) {
                    earliest_arrival[v] = arr_time;
                    heap.emplace(arr_time, v);
                }
            }
        }

        int arrival_time = earliest_arrival[destination_airport];

        if (arrival_time == INT_MAX) {
            stranded = true;
            break; // No es posible llegar al destino desde este punto de cancelación
        } else {
            int delay = arrival_time - original_arrival_time;
            if (delay > max_delay) {
                max_delay = delay;
            }
        }
    }

    // Imprimir el resultado según las condiciones
    if (stranded) {
        cout << "stranded" << endl;
    } else if (max_delay <= 0) {
        cout << "0" << endl;
    } else {
        cout << max_delay << endl;
    }

    return 0;
}
