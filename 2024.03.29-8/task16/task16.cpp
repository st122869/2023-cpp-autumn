#include <iostream>
#include<fstream>

struct SEdge {
    int a;
    int b;
    int w;
    SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
    SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
    ~SEdge() {}
    void set(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
    friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
    stream << edge.a << " " << edge.b;
    if (edge.w > 1)
    {
        stream << " " << edge.w;
    }
    return stream;
}

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
    void ReadMatrix(int vertexes, std::ifstream& in);
    void ReadEdges(int edges, std::istream& in);
    void initMatrixFromEdges();
    void reshenie(int vertexes);

private:
    void init();
    void disposeMatrix();
    void initMatrix();
    void dispose();
    int _vertexes;
    int** _matrix;
    void disposeEdges();
    int _edges;
    int** _edge;
    void initEdges();
};

void CGraph::disposeEdges()
{
    if (_edge != nullptr)
    {
        delete[] _edge;
        _edge = nullptr;
    }
}

void CGraph::init()
{
    dispose();
    initMatrix();
    initEdges();
}

void CGraph::dispose()
{
    disposeMatrix();
    disposeEdges();
}

CGraph::CGraph()
    : _vertexes(0), _edges(0), _matrix(nullptr), _edge(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
    : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edge(nullptr)
{
    init();
}

CGraph::~CGraph()
{
    dispose();
}

void CGraph::ReadMatrix(int vertexes, std::ifstream& in)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            in >> _matrix[i][j];
        }
    }
}

void CGraph::disposeMatrix()
{
    if (_matrix != nullptr)
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            delete[] _matrix[i];
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
}

void CGraph::initMatrix()
{
    if (_vertexes == 0)
    {
        return;
    }
    _matrix = new int* [_vertexes];
    for (int i = 0; i < _vertexes; ++i)
    {
        _matrix[i] = new int[_vertexes] { 0 };
    }
}

void CGraph::initEdges()
{
    if (_edges == 0)
    {
        return;
    }

    _edge = new int* [_edges];
    for (int i = 0; i < _edges; i++)
    {
        _edge[i] = new int[2] { 0 };
    }
}

void CGraph::reshenie(int vertexes)
{
    _vertexes = vertexes;
    const int MAX_V = 30001;
    int parent[MAX_V] = { 0 };
    bool visited[MAX_V] = { false };

        int otdel1, otdel2;
        std::cin >> otdel1;
        std::cin >> otdel2;
        parent[1] = -1;

        for (int i = 2; i <= _vertexes; ++i) 
        {
            std::cin >> parent[i];
        }

        while (otdel1 != -1) 
        {
            visited[otdel1] = true;
            otdel1 = parent[otdel1];
        }

        while (!visited[otdel2]) 
        {
            otdel2 = parent[otdel2];
        }

        std::cout << otdel2;
}

int main(int argc, char* argv[])
{
    int vertexes = 0;
    std::cin >> vertexes;
    CGraph otdel;
    otdel.reshenie(vertexes);

    return EXIT_SUCCESS;
}