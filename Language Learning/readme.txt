This is a directory dedicated to doing the same project in various programming languages. 

To create something in every language's directory I'm gonna use:
        
find . -mindepth 1 -maxdepth 1 -type d -exec touch {}/filename.extension \;

        find . -type d 
                -finding all directories in the current directory
                -We can use -mindepth or maxdepth to define the subdirectory scope, this can be usefull so we dont create file in the wrong place
                -

        -exec touch {}/filename.extension \;
                -results found are stored in {} so touch knows in what directories to create the file

