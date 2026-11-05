#include <windows.h>
#include <string>
#include "GerenciadorSistema.hpp"
#include "Ponto.hpp"

enum { ID_COD = 1, ID_SENHA, ID_LOGIN, ID_ENTRADA, ID_SAIDA,
       ID_HIST, ID_CONSJUS, ID_DATA, ID_MOTIVO, ID_ENVJUS };

static GerenciadorSistema* sistema = nullptr;
static Funcionario* logado = nullptr;
static HWND hCod, hSenha, hData, hMotivo, hSaida;

static std::string ler(HWND h) {
    int n = GetWindowTextLengthA(h);
    std::string s(n + 1, '\0');
    GetWindowTextA(h, &s[0], n + 1);
    s.resize(n);
    return s;
}

static void mostrar(const std::string& t) {
    std::string r;
    for (char c : t) {
        if (c == '\n') r += "\r\n";
        else if (c != '\r') r += c;
    }
    SetWindowTextA(hSaida, r.c_str());
}

static HWND criar(const char* cls, const char* txt, DWORD estilo,
                  int x, int y, int w, int h, HWND pai, int id) {
    return CreateWindowA(cls, txt, WS_CHILD | WS_VISIBLE | estilo,
                         x, y, w, h, pai, (HMENU)(INT_PTR)id,
                         GetModuleHandle(nullptr), nullptr);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CREATE:
        criar("STATIC", "Codigo:", 0, 10, 14, 50, 20, hwnd, 0);
        hCod   = criar("EDIT", "", WS_BORDER, 65, 10, 80, 24, hwnd, ID_COD);
        criar("STATIC", "Senha:", 0, 155, 14, 45, 20, hwnd, 0);
        hSenha = criar("EDIT", "", WS_BORDER | ES_PASSWORD, 205, 10, 120, 24, hwnd, ID_SENHA);
        criar("BUTTON", "Entrar", BS_PUSHBUTTON, 335, 9, 80, 26, hwnd, ID_LOGIN);

        criar("BUTTON", "Registrar entrada", BS_PUSHBUTTON, 10, 45, 130, 28, hwnd, ID_ENTRADA);
        criar("BUTTON", "Registrar saida",   BS_PUSHBUTTON, 145, 45, 130, 28, hwnd, ID_SAIDA);
        criar("BUTTON", "Historico",         BS_PUSHBUTTON, 280, 45, 100, 28, hwnd, ID_HIST);
        criar("BUTTON", "Ver justificativas",BS_PUSHBUTTON, 385, 45, 130, 28, hwnd, ID_CONSJUS);

        criar("STATIC", "Data:", 0, 10, 89, 35, 20, hwnd, 0);
        hData   = criar("EDIT", "", WS_BORDER, 50, 85, 100, 24, hwnd, ID_DATA);
        criar("STATIC", "Motivo:", 0, 160, 89, 45, 20, hwnd, 0);
        hMotivo = criar("EDIT", "", WS_BORDER | ES_AUTOHSCROLL, 210, 85, 200, 24, hwnd, ID_MOTIVO);
        criar("BUTTON", "Enviar justificativa", BS_PUSHBUTTON, 420, 84, 140, 26, hwnd, ID_ENVJUS);

        hSaida = criar("EDIT", "", WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_READONLY,
                       10, 120, 550, 280, hwnd, 0);
        return 0;

    case WM_COMMAND:
        switch (LOWORD(wp)) {
        case ID_LOGIN: {
            try {
                logado = sistema->login(std::stoi(ler(hCod)), ler(hSenha));
            } catch (...) { logado = nullptr; }
            mostrar(logado ? "Login realizado: " + logado->consultarNome()
                           : "Codigo ou senha invalidos.");
            break;
        }
        case ID_ENTRADA:
            if (!logado) { mostrar("Faca login primeiro."); break; }
            sistema->registrarEntrada(logado);
            mostrar("Entrada registrada.");
            break;
        case ID_SAIDA:
            if (!logado) { mostrar("Faca login primeiro."); break; }
            sistema->registrarSaida(logado);
            mostrar("Saida registrada.");
            break;
        case ID_HIST:
            mostrar(sistema->consultarHistorico(logado));
            break;
        case ID_CONSJUS:
            mostrar(sistema->consultarJustificativas(logado));
            break;
        case ID_ENVJUS:
            if (!logado) { mostrar("Faca login primeiro."); break; }
            sistema->enviarJustificativa(logado, ler(hData), ler(hMotivo), "Pendente");
            mostrar("Justificativa enviada.");
            break;
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int show) {
    // ===== CARGA INICIAL: copie do seu main.cpp original =====
    Ponto* ponto = new Ponto();                 // ajuste ao construtor real
    sistema = new GerenciadorSistema(ponto);
    // sistema->adicionarFuncionario(new Funcionario("Ana", "123", 1, ponto));
    // sistema->adicionarRH(new RH(...));
    // =========================================================

    WNDCLASSA wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "PontoGUI";
    RegisterClassA(&wc);

    HWND hwnd = CreateWindowA("PontoGUI", "Sistema de Ponto",
                              WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
                              CW_USEDEFAULT, CW_USEDEFAULT, 590, 450,
                              nullptr, nullptr, hInst, nullptr);
    ShowWindow(hwnd, show);

    MSG m;
    while (GetMessageA(&m, nullptr, 0, 0)) {
        TranslateMessage(&m);
        DispatchMessageA(&m);
    }
    return 0;
}
