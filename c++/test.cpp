
#include <iostream>
#include <list>
#include <unordered_map>
#include <sstream>
#include <regex>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class FileData
{
public:
  string data;
  vector<string> versionHistory;
  stack<string> undoStack;
  queue<string> redoQueue;

  FileData() {}

  FileData(const string &data) : data(data)
  {
    versionHistory.push_back(data);
  }
};

class FileGraph
{
private:
  unordered_map<string, list<string>> graph;
  unordered_map<string, FileData> fileData;

public:
  void addFile(const string &fileName)
  {
    graph[fileName] = list<string>();
    fileData[fileName] = FileData();
    cout << "File '" << fileName << "' added successfully." << endl;
  }

  void removeFile(const string &fileName)
  {
    graph.erase(fileName);
    fileData.erase(fileName);
    cout << "File '" << fileName << "' removed successfully." << endl;
  }

  void editFile(const string &fileName)
  {
    if (fileData.find(fileName) != fileData.end())
    {
      string newData;
      cout << "Enter new data for file '" << fileName << "': ";
      cin.ignore();
      getline(cin, newData);

      // Save the current data to the undo stack
      fileData[fileName].undoStack.push(fileData[fileName].data);

      fileData[fileName].data = newData;
      fileData[fileName].versionHistory.push_back(newData);

      // Clear the redo queue when a new edit is made
      while (!fileData[fileName].redoQueue.empty())
      {
        fileData[fileName].redoQueue.pop();
      }

      cout << "File data updated successfully. New version created." << endl;
    }
    else
    {
      cout << "File '" << fileName << "' not found." << endl;
    }
  }

  void undoEdit(const string &fileName)
  {
    if (fileData.find(fileName) != fileData.end() && !fileData[fileName].undoStack.empty())
    {
      // Move the current data to the redo queue
      fileData[fileName].redoQueue.push(fileData[fileName].data);

      // Pop the previous state from the undo stack
      fileData[fileName].data = fileData[fileName].undoStack.top();
      fileData[fileName].undoStack.pop();

      cout << "Undo operation successful." << endl;
    }
    else
    {
      cout << "Undo not possible for file '" << fileName << "'." << endl;
    }
  }

  void redoEdit(const string &fileName)
  {
    if (fileData.find(fileName) != fileData.end() && !fileData[fileName].redoQueue.empty())
    {
      // Move the current data to the undo stack
      fileData[fileName].undoStack.push(fileData[fileName].data);

      // Pop the next state from the redo queue
      fileData[fileName].data = fileData[fileName].redoQueue.front();
      fileData[fileName].redoQueue.pop();

      cout << "Redo operation successful." << endl;
    }
    else
    {
      cout << "Redo not possible for file '" << fileName << "'." << endl;
    }
  }

  void displayVersionHistory(const string &fileName)
  {
    if (fileData.find(fileName) != fileData.end())
    {
      cout << "Version history for file '" << fileName << "':\n";
      for (size_t i = 0; i < fileData[fileName].versionHistory.size(); ++i)
      {
        cout << "Version " << i + 1 << ":\n"
             << fileData[fileName].versionHistory[i] << "\n\n";
      }
    }
    else
    {
      cout << "File '" << fileName << "' not found." << endl;
    }
  }

  void displayFiles()
  {
    cout << "Files in the system: ";
    for (const auto &file : graph)
    {
      cout << file.first << " ";
    }
    cout << endl;
  }

  void displayFileData(const string &fileName)
  {
    if (fileData.find(fileName) != fileData.end())
    {
      cout << "Data in file '" << fileName << "': " << fileData[fileName].data << endl;
    }
    else
    {
      cout << "File '" << fileName << "' not found." << endl;
    }
  }

  void analyzeFileData(const string &fileName)
  {
    if (fileData.find(fileName) != fileData.end())
    {
      istringstream iss(fileData[fileName].data);
      string word;
      int wordCount = 0;
      while (iss >> word)
      {
        ++wordCount;
      }
      cout << "Analysis of file '" << fileName << "': Word count = " << wordCount << endl;
    }
    else
    {
      cout << "File '" << fileName << "' not found." << endl;
    }
  }

  void compareFiles(const string &fileName1, const string &fileName2)
  {
    if (fileData.find(fileName1) != fileData.end() && fileData.find(fileName2) != fileData.end())
    {
      if (fileData[fileName1].data == fileData[fileName2].data)
      {
        cout << "Files '" << fileName1 << "' and '" << fileName2 << "' have the same data." << endl;
      }
      else
      {
        cout << "Files '" << fileName1 << "' and '" << fileName2 << "' have different data." << endl;
      }
    }
    else
    {
      cout << "One or more files not found." << endl;
    }
  }

  void autoComplete(const string &fileName, const string &partialWord)
  {
    if (fileData.find(fileName) != fileData.end())
    {
      istringstream iss(fileData[fileName].data);
      string word;
      vector<string> suggestions;

      while (iss >> word)
      {
        if (word.find(partialWord) == 0)
        {
          suggestions.push_back(word);
        }
      }

      if (!suggestions.empty())
      {
        cout << "Auto-complete suggestions for '" << partialWord << "' in file '" << fileName << "': ";
        for (const auto &suggestion : suggestions)
        {
          cout << suggestion << " ";
        }
        cout << endl;
      }
      else
      {
        cout << "No suggestions found for '" << partialWord << "' in file '" << fileName << "'." << endl;
      }
    }
    else
    {
      cout << "File '" << fileName << "' not found." << endl;
    }
  }

  void renameFile(const string &oldFileName, const string &newFileName)
  {
    auto it = fileData.find(oldFileName);
    if (it != fileData.end())
    {
      // Update fileData and graph with the new file name
      fileData[newFileName] = move(it->second);
      fileData.erase(it);

      // Update dependencies in the graph
      graph[newFileName] = move(graph[oldFileName]);
      graph.erase(oldFileName);

      cout << "File '" << oldFileName << "' renamed to '" << newFileName << "' successfully." << endl;
    }
    else
    {
      cout << "File '" << oldFileName << "' not found." << endl;
    }
  }

  void advancedSearch(const string &fileName, const string &pattern)
  {
    if (fileData.find(fileName) != fileData.end())
    {
      istringstream iss(fileData[fileName].data);
      string line;
      int lineNumber = 1;

      while (getline(iss, line))
      {
        if (regex_search(line, regex(pattern)))
        {
          cout << "Match found in file '" << fileName << "' at line " << lineNumber << ": " << line << endl;
        }
        lineNumber++;
      }
    }
    else
    {
      cout << "File '" << fileName << "' not found." << endl;
    }
  }
};

int main()
{
  FileGraph fileGraph;

  int choice;
  do
  {
    cout << "\nMenu:\n";
    cout << "1. Add File\n";
    cout << "2. Remove File\n";
    cout << "3. Edit File\n";
    cout << "4. Undo Edit\n";
    cout << "5. Redo Edit\n";
    cout << "6. Rename File\n";
    cout << "7. Display Files\n";
    cout << "8. Display File Data\n";
    cout << "9. Analyze File Data\n";
    cout << "10. Compare Files\n";
    cout << "11. Auto-Complete\n";
    cout << "12. Display Version History\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:


    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.addFile(fileName);
      break;
    }
    case 2:
    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.removeFile(fileName);
      break;
    }
    case 3:
    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.editFile(fileName);
      break;
    }
    case 4:
    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.undoEdit(fileName);
      break;
    }
    case 5:
    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.redoEdit(fileName);
      break;
    }
    case 6:
    {
      string oldFileName, newFileName;
      cout << "Enter old file name: ";
      cin >> oldFileName;
      cout << "Enter new file name: ";
      cin >> newFileName;
      fileGraph.renameFile(oldFileName, newFileName);
      break;
    }
    case 7:
    {
      fileGraph.displayFiles();
      break;
    }
    case 8:
    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.displayFileData(fileName);
      break;
    }
    case 9:
    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.analyzeFileData(fileName);
      break;
    }
    case 10:
    {
      string fileName1, fileName2;
      cout << "Enter first file name: ";
      cin >> fileName1;
      cout << "Enter second file name: ";
      cin >> fileName2;
      fileGraph.compareFiles(fileName1, fileName2);
      break;
    }
    case 11:
    {
      string fileName, partialWord;
      cout << "Enter file name: ";
      cin >> fileName;
      cout << "Enter partial word for auto-complete: ";
      cin >> partialWord;
      fileGraph.autoComplete(fileName, partialWord);
      break;
    }
    case 12:
    {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      fileGraph.displayVersionHistory(fileName);
      break;
    }
    case 0:
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);

  return 0;
}

