EXEC=$1
TMP_OUT=$2

for i in {1..13..1}; do
  testname=$(printf "%01d" $i)
  $EXEC < casos_teste/input0$testname.txt > $TMP_OUT
  if ! diff -qwB casos_teste/out0$testname.txt $TMP_OUT &>/dev/null; then
    diff -wBy casos_teste/out0$testname.txt $TMP_OUT > output/$testname.txt
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done
rm $TMP_OUT