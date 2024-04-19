#include <iostream>

class CGraph 
{
public:
    CGraph();
    CGraph(int vertexes);
    ~CGraph();
    void readList();
    void printMatrix();

private:
    int _vertexes;
    int** _matrix;
    void init();
    void dispose();
    void disposeMatrix();
    void initMatrix();
};

CGraph::CGraph()
    : _vertexes(0), _matrix(nullptr) {}

CGraph::CGraph(int vertexes)
    : _vertexes(vertexes), _matrix(nullptr)
{
    init();
}

CGraph::~CGraph()
{
    dispose();
}

void CGraph::init()
{
    dispose();
    initMatrix();
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

void CGraph::dispose()
{
    disposeMatrix();
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

void CGraph::readList() 
{
    for (int i = 0; i < _vertexes; ++i) 
    {
        int edgeCount;
        std::cin >> edgeCount;
        for (int j = 0; j < edgeCount; ++j) 
        {
            int vertex;
            std::cin >> vertex;
            _matrix[i][vertex - 1] = 1;
        }
    }
}

void CGraph::printMatrix() 
{
    std::cout << _vertexes << std::endl;
    for (int i = 0; i < _vertexes; ++i) 
    {
        for (int j = 0; j < _vertexes; ++j) 
        {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;

    CGraph graph;

    graph.readList();
    graph.printMatrix();

    return EXIT_SUCCESS;
}