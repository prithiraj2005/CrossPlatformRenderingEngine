#pragma once
#include <map>
#include <vector>

namespace Library
{
    enum TextureType
    {
        TextureTypeDifffuse = 0,
        TextureTypeSpecularMap,
        TextureTypeAmbient,
        TextureTypeEmissive,
        TextureTypeHeightmap,
        TextureTypeNormalMap,
        TextureTypeSpecularPowerMap,
        TextureTypeDisplacementMap,
        TextureTypeLightMap,
        TextureTypeEnd
    };

    class ModelMaterial
    {
        friend class Model;

    public:
        ModelMaterial(Model& model);
        ~ModelMaterial();

        Model& GetModel();
        const std::string& Name() const;
        const std::map<TextureType, std::vector<std::string>*> Textures() const;
		void LoadMaterial(std::ifstream& inFile);

    private:		
		ModelMaterial(Model& model, std::ifstream& inputFile);
        ModelMaterial(const ModelMaterial& rhs);
        ModelMaterial& operator=(const ModelMaterial& rhs);

        Model& mModel;
        std::string mName;
        std::map<TextureType, std::vector<std::string>*> mTextures;		
    };
}