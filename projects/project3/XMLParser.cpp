// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

XMLParser::XMLParser()
{
  parseStack = new Stack<TokenStruct>;
  elementNameBag = new Bag<std::string>;
}  // end default constructor

XMLParser::~XMLParser()
{
  delete parseStack;
  delete elementNameBag;
}  // end destructor

bool XMLParser::tokenizeInputString(const std::string &inputString)
{
  for(int i = 0; i < inputString.length(); i++) {
    std::string tagStr;
    TokenStruct testToken;
    if(inputString[i] == '<') {
      for(char ch : badStartChars) {
        if(inputString[i+1] == ch) {tokenized = false; return tokenized;}
      }
      if((inputString[i+1] >= 'a' && inputString[i+1] <= 'z') 
	|| (inputString[i+1] >= 'A' && inputString[i+1] <= 'Z')) {
        while(inputString[i+1] != '/' && inputString[i+1] != '>') {
          tagStr += inputString[i+1];
          i++;
        }

	tagStr = deleteAttributes(tagStr);
	for(char ch1 : tagStr) {
          for(char ch2 : badChars) {
            if(ch1 == ch2) {tokenized = false; return tokenized;}
	  }
	}
         
	if(inputString[i+1] == '/') {testToken.tokenType = EMPTY_TAG;}
	else {testToken.tokenType = START_TAG;}
      }
      
      else if(inputString[i] == '/') {
        for(char ch : badStartChars) {
          if(inputString[i+1] == ch) {tokenized = false; return false;}
	  for(i = i; inputString[i+1] != '>'; i++) {
            if(inputString[i+1] == '<') {tokenized = false; return tokenized;}
	    tagStr += inputString[i+1];
	  }
	}
      }

      else if(inputString[i] == '?') {
        for(i = i; inputString[i+1] != '?'; i++) {
          if(inputString[i+1] == '<') {tokenized = false; return tokenized;}
	  tagStr += inputString[i+1];
	}
      }
    }

    else if(inputString[i] != ' ' && inputString[i] != '>') {
      for(i = i; inputString[i] != '<'; i++) {tagStr += inputString[i];}
      testToken.tokenType = CONTENT;
      i--;
    }

    if(!tagStr.empty()) {
      testToken.tokenString = tagStr;
      tokenizedInputVector.push_back(testToken);
      if(testToken.tokenType != END_TAG) {elementNameBag->add(testToken.tokenString);}
    }
  }
  tokenized = true;
  return tokenized;
}  // end

std::string XMLParser::deleteAttributes(std::string input)
{
  std::string str;
  for(char ch : input) {
    if(ch == ' ') {break;}
    else {str += ch;}
  }
  return str;
}

bool XMLParser::parseTokenizedInput()
{
  for(TokenStruct testToken : tokenizedInputVector) {
    if(testToken.tokenType == START_TAG) {parseStack->push(testToken);}
    else if(testToken.tokenType == END_TAG) {
      if(parseStack->peek().tokenString == testToken.tokenString
	&& parseStack->peek().tokenType == START_TAG) {
        parseStack->pop();
      } else {parsed = false; return parsed;}
    } 
  }
  parsed = parseStack->isEmpty();
  return parsed;
}

void XMLParser::clear()
{
  parseStack->clear();
  elementNameBag->clear();
  tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

bool XMLParser::containsElementName(const std::string &inputString) const
{
  if(!parsed || !tokenized) {return false;}
  else {return elementNameBag->contains(inputString);}
}

int XMLParser::frequencyElementName(const std::string &inputString) const
{
  if(!parsed || !tokenized) {return false;}
  else {return elementNameBag->getFrequencyOf(inputString);}
}

