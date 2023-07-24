parameters=$@
cppfiles=()
re='\.cpp$'
for x in $parameters; do
    [[ $x =~ $re  ]] && cppfiles+=("$x")
done

echo "${#cppfiles[@]} detected"
for x in ${cppfiles[@]}; do
    echo "Checking $x .."
    cat $x | sed -n -e '1p' -e '5,$p' > .cpplint.cpp
    cpplint --filter=-legal/copyright,-build/namespaces,-runtime/string,-whitespace/newline
done;
