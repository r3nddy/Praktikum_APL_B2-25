#ifndef JSON_STORAGE_H
#define JSON_STORAGE_H

#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "json/json.hpp"

namespace jsonstorage {

nlohmann::json logistikToJson(const Logistik &item) {
    return {
        {"idLogistik", item.idLogistik},
        {"mineral", {
            {"namaMineral", item.mineral.namaMineral},
            {"jenisMineral", item.mineral.jenisMineral},
            {"kuantitas", item.mineral.kuantitas},
            {"satuan", item.mineral.satuan}
        }},
        {"asal", {
            {"asalTambang", item.asal.asalTambang}
        }},
        {"tanggal", item.tanggal},
        {"status", item.status}
    };
}

void simpanLogistikKeJson(const Logistik *logistik, int jumlahLogistik, const std::string &namaFile) {
    nlohmann::json data = nlohmann::json::array();
    for (int i = 0; i < jumlahLogistik; i++) {
        data.push_back(logistikToJson(logistik[i]));
    }

    std::ofstream outFile(namaFile);
    if (!outFile.is_open()) {
        throw std::runtime_error("[RUNTIME] Gagal membuat file JSON.");
    }

    outFile << std::setw(4) << data << std::endl;
}

bool muatLogistikDariJson(Logistik *logistik, int *jumlahLogistik, int kapasitas, const std::string &namaFile) {
    std::ifstream inFile(namaFile);
    if (!inFile.is_open()) {
        return false;
    }

    nlohmann::json data;
    inFile >> data;

    if (!data.is_array()) {
        throw std::runtime_error("[RUNTIME] Format JSON tidak valid (harus array).");
    }

    int total = 0;
    for (const auto &item : data) {
        if (total >= kapasitas) {
            break;
        }

        Logistik *ptr = logistik + total;
        ptr->idLogistik = item.at("idLogistik").get<int>();
        ptr->mineral.namaMineral = item.at("mineral").at("namaMineral").get<std::string>();
        ptr->mineral.jenisMineral = item.at("mineral").at("jenisMineral").get<std::string>();
        ptr->mineral.kuantitas = item.at("mineral").at("kuantitas").get<double>();
        ptr->mineral.satuan = item.at("mineral").at("satuan").get<std::string>();
        ptr->asal.asalTambang = item.at("asal").at("asalTambang").get<std::string>();
        ptr->tanggal = item.at("tanggal").get<std::string>();
        ptr->status = item.at("status").get<std::string>();
        total++;
    }

    if (total == 0) {
        return false;
    }

    *jumlahLogistik = total;
    return true;
}

} // namespace jsonstorage

#endif
