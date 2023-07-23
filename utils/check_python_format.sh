parameters=$@
python_files=()
re='\.py$'
for x in $parameters; do
    [[ $x =~ $re  ]] && python_files+=("$x")
done

echo $python_files
echo "${#python_files[@]} detected"
for x in ${python_files[@]}; do
    echo "Checking $x .."
    black --check $x
done;
