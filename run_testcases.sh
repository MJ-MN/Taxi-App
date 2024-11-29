APP_NAME="main"
TEST_DIR="../tests"

make clean
make
for dir in "${TEST_DIR}"/*/; do
    cp ./bin/$APP_NAME "$dir"
    TEST_NUMBER=$(echo "{$dir}" | grep -Eo '[0-9]{1,}' | sed -n '1p')
    echo "RUNNING TEST CASE #$TEST_NUMBER"
    echo "**************************************************************"
    ./"$dir"/$APP_NAME < "$dir"test$TEST_NUMBER.in > "$dir"$TEST_NUMBER.out
    if [ "$1" == "-d" ]
    then
        diff "$dir"$TEST_NUMBER.out "$dir"test$TEST_NUMBER.out
    fi
    echo "**************************************************************"
done
