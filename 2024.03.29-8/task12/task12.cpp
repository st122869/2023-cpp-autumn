#include <iostream>
#include<fstream>

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes);
    ~CGraph();
    void ReadMatrix(int vertexes, std::ifstream& stream);
    int getEdgesCountFromMatrix();
    void countEdges();
    void check();

private:
    void disposeMatrix();
    void initMatrix();
    int _vertexes;
    int** _matrix;
    void init();
    void dispose();
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

CGraph::CGraph(int vertexes)
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

int CGraph::getEdgesCountFromMatrix()
{
    int count = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            count += (_matrix[i][j] != 0);
        }
    }
    return count / 2;
}

void CGraph::countEdges()
{
    std::cout << getEdgesCountFromMatrix() << std::endl;
}

void CGraph::check()
{
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (_matrix[i][j] == _matrix[j][i])
            {
                k++;
            }
        }
    }
    if (k == 25)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "YES";
    }
}

int main(int argc, char* argv[])
{
    std::ifstream in("task12.txt");
    CGraph edges;
    edges.ReadMatrix(5, in);
    edges.check();

    return EXIT_SUCCESS;
}