#pragma once

#include <vector>

namespace SeaEngine
{
    struct Vertex
    {
        struct Position
        {
            float x;
            float y;
            float z;
        } position{};

        struct TextureCoordinate
        {
            float u;
            float v;
        } textureCoordinate{};
    };

	class Mesh
	{
		public:
            Mesh() {};
            ~Mesh() {};
            Mesh(const Mesh&) = delete;

            const std::vector<Vertex>& vertices() const;
            const std::vector<int>& indices() const;

            void addVertex(const Vertex& vertex);
            void addIndex(int index);

		private:
            std::vector<Vertex> vertices_;
            std::vector<int> indices_;
	};
}
