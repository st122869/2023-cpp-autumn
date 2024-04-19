#include <iostream>
#include<fstream>

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
    void ReadMatrix(int vertexes, std::ifstream& stream);
    void countStepen();

private:
    void init();
    void disposeMatrix();
    void initMatrix();
    void dispose();
    int _vertexes;
    int** _matrix;
};

void CGraph::init()
{
    dispose();
    initMatrix();
}

void CGraph::dispose()
{
    disposeMatrix();
}

CGraph::CGraph()
    : _vertexes(0), _matrix(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
    : _vertexes(vertexes), _matrix(nullptr)
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

void CGraph::countStepen()
{
    int k = 0;
    for (int i = 0; i < 5; i++) 
    {
        k = 0;
        for (int j = 0; j < 5; j++)
        {
            if (_matrix[i][j] == 1)
            {
                k++;
            }
        }
        std::cout << k << " ";
    }
}

int main(int argc, char* argv[])
{
    std::ifstream in("task10.txt");
    CGraph degree;
    degree.ReadMatrix(5, in);
    degree.countStepen();

    return EXIT_SUCCESS;
}