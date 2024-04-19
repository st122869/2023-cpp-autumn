#include <iostream>
#include<fstream>

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();
    void ReadMatrix(int vertexes, std::ifstream& stream);
    void stoki(int vertexes);
    void istoki(int vertexes);

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
    for (int i = 1; i < _vertexes +1; ++i)
    {
        for (int j = 1; j < _vertexes+1; ++j)
        {
            in >> _matrix[i][j];
        }
    }
}

void CGraph::disposeMatrix()
{
    if (_matrix != nullptr)
    {
        for (int i = 1; i < _vertexes +1; ++i)
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
    for (int i = 1; i < _vertexes +1; ++i)
    {
        _matrix[i] = new int[_vertexes] { 0 };
    }
}

void CGraph::stoki(int vertexes)
{
    _vertexes = vertexes;
    for (int i = 1; i < _vertexes +1; i++)
    {
        int count = 0;
        for (int j = 1; j < _vertexes +1; j++)
        {
            if (_matrix[i][j] == 0)
            {
                count++;
            }
        }
        if (count == 5)
        {
            std::cout << i << " ";
        }
    }
}

void CGraph::istoki(int vertexes)
{
    _vertexes = vertexes;
    for (int i = 1; i < _vertexes + 1; i++)
    {
        int count = 0;
        for (int j = 1; j < _vertexes + 1; j++)
        {
            if (_matrix[j][i] == 0)
            {
                count++;
            }
        }
        if (count == 5)
        {
            std::cout << i << " ";
        }
    }
    std::cout<<std::endl;
}


int main(int argc, char* argv[])
{
    std::ifstream in("task14.txt");
    CGraph edges;
    edges.ReadMatrix(5, in);
    edges.istoki(5);
    edges.stoki(5);

    return EXIT_SUCCESS;
}