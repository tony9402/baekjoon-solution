echo "Check Python solutions"
python_files=`find solutions -name "*.py"`

if [[ ${#python_files} > 0 ]]; then
    ./utils/check_python_format.sh $python_files
fi

echo "Check C++ solutions"
cpp_files=`find solutions -name "*.cpp"`

if [[ ${#cpp_files} > 0 ]]; then
    ./utils/check_cpp_format.sh $cpp_files
fi
