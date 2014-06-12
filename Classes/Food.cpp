#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Food.h"
#include "EffectFactory.h"
#include "json\prettywriter.h"
#include "json\document.h"
#include "RandomNum.h"

bool Food::init(){
    this->initWithFile( getFoodImage() );
    effect = EffectFactory::createRandomEffect();
    return true;
}

std::string Food::getFoodImage(){

    std::string filePath = FileUtils::getInstance()->fullPathForFilename( "foodimages.json" );
    std::string contentStr = FileUtils::getInstance()->getStringFromFile( filePath );
    rapidjson::Document doc;
    doc.Parse<0>( contentStr.c_str() );
    auto& array = doc["images"];

    int choice = nrand( 1, array.Size() );
    return array[choice].GetString();
}

void Food::setGridPosition( Position pos ){
    setPosition( ( pos.col + 0.5 ) * getContentSize().width, ( TILE_MAP_ROW_SIZE - 0.5 - pos.row ) * getContentSize().height );
    position = pos;
}