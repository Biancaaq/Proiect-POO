#ifndef EROAREFISIER_HPP
#define EROAREFISIER_HPP

#include <exception>
#include <string>

class EroareFisier : public std::exception {
    std::string mesaj;

    public:
    explicit EroareFisier(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareParsingJSON : public std::exception {
    std::string mesaj;

    public:
    explicit EroareParsingJSON(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareInput : public std::exception {
    std::string mesaj;

    public:
    explicit EroareInput(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareUpgrade : public std::exception {
    std::string mesaj;

    public:
    explicit EroareUpgrade(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareEnergie : public std::exception {
    std::string mesaj;

    public:
    explicit EroareEnergie(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareBani : public std::exception {
    std::string mesaj;

    public:
    explicit EroareBani(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareMateriale : public std::exception {
    std::string mesaj;

    public:
    explicit EroareMateriale(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroarePointerNull : public std::exception {
    std::string mesaj;

    public:
    explicit EroarePointerNull(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareAplicatie : public std::exception {
    std::string mesaj;

    public:
    explicit EroareAplicatie(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class EroareRucsacGol : public std::exception {
    std::string mesaj;

    public:
    explicit EroareRucsacGol(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class JocCastigat : public std::exception {
    std::string mesaj;

public:
    explicit JocCastigat(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};


#endif